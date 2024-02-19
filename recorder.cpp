// recorder.cpp
#include "recorder.h"


Recorder::Recorder(Synth* s) : synth(s), specialNote("end") {}

void Recorder::addPlayedNote(const std::string& note, float freq) {
    recordedNotes.push_back(note);
    recordedNotesfreq.push_back(freq);
}

bool Recorder::isSequenceFinished() const {
    if (!recordedNotes.empty() && recordedNotes.back() == specialNote) {
        return true;
    }
    return false;
}

void Recorder::playRecordedNotes(std::string instru) const {
  synth-> setParamValue("gain",2);
  synth->setParamValue("gate"+instru,1);
    for (const auto& note : recordedNotesfreq) {
        
        // Ajoutez ici la logique pour jouer chaque note
        if (note == 0.0){
          break ;
        }
        std::cout << "Playing note: " << note << std::endl;
        synth->setParamValue("freq" + instru,note);
        delay(600);   
    }
    synth->setParamValue("gate" + instru,0);
}

std::vector<std::string> Recorder::Notes(){
    return recordedNotes;
}

std::vector<float> Recorder::freq(){
    return recordedNotesfreq;
}

void Recorder::clearRecordedNotes() {
    recordedNotes.clear();
}


std::string Recorder::charToString(const char *charArray) {
    // Utilisez le constructeur de std::string pour convertir le const char * en std::string
    std::string result(charArray);
    return result;
}
