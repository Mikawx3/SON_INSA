// recorder.h
#ifndef RECORDER_H
#define RECORDER_H

#include <iostream>
#include <vector>
#include <string>
#include "Synth.h"


class Recorder {
public:
    // Constructeur
    Recorder(Synth* s);

    // Méthode pour ajouter une note jouée
    void addPlayedNote(const std::string& note,float freq);

    // Méthode pour vérifier si la séquence de notes jouée est terminée
    bool isSequenceFinished() const;

    // Méthode pour jouer les notes enregistrées
    void playRecordedNotes(std::string instru) const;

    // Méthode pour effacer les notes enregistrées
    void clearRecordedNotes();

    // Retourne les notes enregistrées
    std::vector<std::string> Notes();

    std::vector<float> freq();

    // conversion char to string

    std::string charToString(const char *charArray);

private:
    std::vector<std::string> recordedNotes; // Vecteur pour stocker les notes enregistrées
    std::vector<float> recordedNotesfreq; // Vecteur pour stocker les notes en fréq enregistrées
    std::string specialNote; // Note spéciale pour indiquer la fin de la séquence
    Synth *synth; // Classe synth de faust qui permet synthétiser les sons des instruments
    
};

#endif
