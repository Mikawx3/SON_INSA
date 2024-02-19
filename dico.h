#ifndef DICO_H
#define DICO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map> 
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>



class Dico {
    
public:

    std::string checkinstru(float freq, const std::map<std::string, std::vector<float>>& dictionary);

    std::map<int, std::vector<float>> notedic();
    int checkmap(float freq, std::map<int, std::vector<float>> dictionary); 
    
    std::map<int, std::vector<float>> getDicoMAP();
    const char * convert(int key);
    
    const char * vocal(int i);
    std::map<int,std::string> getCommande();
    std::map<std::string, std::vector<float>> getDicoinstru();
    
private:
    
    const std::map<int, std::vector<float>> DicoMAP = {
      {1, {261, 262}},   // Do 4 (C4)
      {2, {293, 294}},   // Ré 4 (D4)
      {3, {329, 330}},   // Mi 4 (E4)
      {4, {349, 350}},   // Fa 4 (F4)
      {5, {391, 393}},   // Sol 4 (G4)
      {6, {439, 441}},   // La 4 (A4)
      {7, {493, 494}},   // Si 4 (B4)
      {8, {523, 524}}    // Do 5 (C5)
};

    std::map<int, const char *> Id_note = {
    {1, "Do 4"},   // Do 4 (C4)
    {2, "Ré 4"},   // Ré 4 (D4)
    {3, "Mi 4"},   // Mi 4 (E4)
    {4, "Fa 4"},   // Fa 4 (F4)
    {5, "Sol 4"},  // Sol 4 (G4)
    {6, "La 4"},   // La 4 (A4)
    {7, "Si 4"},   // Si 4 (B4)
    {8, "Do 5"}    // Do 5 (C5)
};

    std::map<int, const char *> Voix = {
    {1, "12.WAV"},    // hello
    {2, "continue"},  // Ré 4 (D4)
    {3, "play"},      // Mi 4 (E4)
    {4, "choose"},    // Fa 4 (F4)
    {5, "Sol 4"},     // Sol 4 (G4)
    {6, "La 4"},      // La 4 (A4)
    {7, "Si 4"},      // Si 4 (B4)
    {8, "Do 5"}       // Do 5 (C5)
};

const std::map<std::string, std::vector<float>> Dicoinstru = {
      {"_flute", {261, 262}},   // Do 4 (C4)
      {"_guitar", {293, 294}},   // Ré 4 (D4)
      {"_violin", {329, 330}},   // Mi 4 (E4)
};


};

#endif
