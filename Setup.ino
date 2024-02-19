#include <Audio.h>
#include "dico.h"
#include "recorder.h"
#include "Synth.h"


Synth synth;

// GUItool: begin automatically generated code

AudioControlSGTL5000     audioShield;    //xy=493.20018768310547,452.0000514984131

AudioInputI2S            in;             //xy=108.20014953613281,249.9999885559082
AudioOutputI2S           out;            //xy=917.2001571655273,230.00000381469727
AudioAnalyzeNoteFrequency notefreq;       //xy=260.200138092041,409.99999046325684

AudioPlaySdWav           sound;          //xy=354.20015716552734,112.0000057220459
AudioMixer4              mixer;         //xy=485.99999237060547,252.00000381469727



AudioConnection          patchCord1(in, 0, notefreq, 0);

AudioConnection          patchCord2(sound, 0, mixer, 0);
AudioConnection          patchCord3(sound, 1, mixer, 1);

AudioConnection          patchCord4(synth, 0, mixer, 2);
AudioConnection          patchCord5(synth, 1, mixer, 3);

AudioConnection          patchCord6(mixer, 0, out, 0);
AudioConnection          patchCord7(mixer, 1, out, 1);


//AudioConnection          patchCord6(sound, 0, out, 0);
//AudioConnection          patchCord7(sound, 1, out, 1);

// GUItool: end automatically generated code




// Use these with the Teensy Audio Shield
#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14

// Initialisation des class

Dico dico;

Synth* synth_p = &synth;
Recorder recorder(synth_p);


// Initialisation des variables / dicos 

std::vector<std::string> recordedNotes; // Vecteur pour stocker les notes enregistrées
std::vector<float> recordedNotesfreq; // Vecteur pour stocker les notes enregistrées freq
std::string specialNote("end"); // Note spéciale pour indiquer la fin de la séquence

std::map<int, std::vector<float>> DicoMAP ;
std::map<std::string, std::vector<float>> Dicoinstru ;
//std::map<int,std::string> Commande;

void setup() {
  AudioMemory(150);
  Serial.begin(9600);
  notefreq.begin(.15);
  audioShield.enable();
  audioShield.inputSelect(AUDIO_INPUT_MIC);
  audioShield.micGain(10); // in dB
  audioShield.volume(0.60);

  // Récupération des dico
  //Commande = dico.getCommande();
  DicoMAP = dico.getDicoMAP();
  
  for (const auto& entry : DicoMAP) {
        std::cout << "Key: " << entry.first << std::endl; // Afficher la clé

        std::cout << "Values: ";
        for (const auto& value : entry.second) {
            std::cout << value << " "; // Afficher les valeurs avec un espace entre chaque valeur
        }
        std::cout << std::endl; // Aller à la ligne pour le prochain élément
    }

  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    // stop here, but print a message repetitively
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
}

void playFile(const char *filename)
{
  Serial.print("Playing file: ");
  Serial.println(filename);

  // Start playing the file.  This sketch continues to
  sound.play(filename);

  // A brief delay for the library read WAV info
  delay(25);

  // Simply wait for the file to finish playing.
  while (sound.isPlaying()) {
  }
}


void loop() {
  const char * son;
  const char * real_note;
  
  DicoMAP = dico.getDicoMAP();
  Dicoinstru = dico.getDicoinstru();

  std::string instru ;

  static bool closed = false ;
  static bool opened = false;
  static bool played = false;
  static bool choosed = false;

//  synth.setParamValue("gate_flute",1);
  

  if (notefreq.available() and !closed) {

    float note = notefreq.read();
    int key = dico.checkmap(note, DicoMAP); // Vérifie la note par rapport à dicoMAP
    

    if (key == 1 && !opened) {
      
        opened = true; // Marque la porte comme ouverte pour ne pas y retourner

        // Jouer le son correspondant à l'ouverture
        son = dico.vocal(key);
        playFile(son);

  
    }
    
    else if (key != 0 && opened && !closed) {

 
      float prob = notefreq.probability();
      
      real_note = dico.convert(key);
         
      Serial.printf("Note: %3.2f | Probability: %.2f\n", note, prob);
      Serial.printf("Note: %s | note: %d\n", real_note, key);

      std::string PlayedNote = recorder.charToString(real_note);
      recorder.addPlayedNote(PlayedNote,note);

      
      delay(500);
      
    }

    if (key == 8 && !closed ){
      closed = true ;
      recorder.addPlayedNote(specialNote,0);

      
    }

    if (recorder.isSequenceFinished()){
      recordedNotes = recorder.Notes();
      recordedNotesfreq = recorder.freq();
      Serial.println("Recorded notes:");
      for (const auto& note : recordedNotes) {
          Serial.printf("%s\n", note.c_str());
      }
      for (const auto& note : recordedNotesfreq) {
          Serial.printf("%.2f\n", note);
      
      
}
  Serial.println("Choisissez votre instrument"); // Assistant vocal parle  
}
}
  if (!choosed and closed){
    
    if(notefreq.available()){
      
      float note = notefreq.read();
      
      std::string key = dico.checkinstru(note, Dicoinstru); // Vérifie la note par rapport à dicoMAP
      Serial.println(key.c_str());
      if(key != ""){
        
        instru = key;
        choosed = true;
      }
    }
  }

  if (!played and closed and choosed){
    recorder.playRecordedNotes(instru);
    played = true ;
  }

}
