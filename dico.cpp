#include "dico.h"



std::map<int, std::vector<float>> Dico::notedic() {
    // Dictionnaire pour stocker les valeurs lues à partir du fichier CSV
    std::map<int, std::vector<float>> dictionary;

    // Nom du fichier CSV à ouvrir
    std::string filename = "notes.csv";
    
    // Ouvrir le fichier CSV en lecture
    std::ifstream file(filename);

    // Vérifier si le fichier est ouvert avec succès
    if (!file.is_open()) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier " << filename << std::endl;
        // Retourner un dictionnaire vide en cas d'erreur
        return dictionary;
    }

    std::string line;
    
    // Lire chaque ligne du fichier
    while (std::getline(file, line)) {
        // Utiliser un stringstream pour traiter la ligne comme une séquence de caractères
        std::stringstream ss(line);
        std::string token;

        // Vecteur pour stocker les éléments de la ligne
        std::vector<float> values;

        // Lire la première colonne qui est la clé du dictionnaire (un entier)
        std::getline(ss, token, ';');
        int key = std::stoi(token);

        // Parcourir le reste de la ligne pour récupérer les valeurs
        while (std::getline(ss, token, ';')) {
            float value = std::stof(token); // Convertir le token en float
            values.push_back(value); // Ajouter la valeur au vecteur
        }

        // Ajouter la paire clé-valeur au dictionnaire
        dictionary[key] = values;
    }

    // Fermer le fichier après avoir terminé la lecture
    file.close();

    // Retourner le dictionnaire rempli
    return dictionary;
}

int Dico::checkmap(float freq, std::map<int, std::vector<float>> dictionary) {
    int key = 0; // Initialiser la clé à 0

    // Parcourir le dictionnaire
    for (auto const& entry : dictionary) {
        // Récupérer les valeurs min et max de la fréquence de la ligne actuelle
        float minFreq = entry.second[0]; // Valeur de la colonne 2 (minimum)
        float maxFreq = entry.second[1]; // Valeur de la colonne 3 (maximum)

        // Vérifier si la fréquence donnée se trouve entre minFreq et maxFreq
        if (freq >= minFreq && freq <= maxFreq) {
            key = entry.first; // Stocker la clé actuelle
            break; // Sortir de la boucle une fois qu'une correspondance est trouvée
        }
    }

    return key;
}

const char * Dico::convert(int key) {
    auto it = Id_note.find(key);
    if (it != Id_note.end()) {
        return it->second; // retourne la chaîne complète associée à la clé
    } else {
        return ""; // ou une valeur par défaut appropriée
    }
}

const char * Dico::vocal(int i) {
    auto it = Voix.find(i);
    if (it != Voix.end()) {
        return it->second; // retourne la chaîne complète associée à la clé
    } else {
        return ""; // ou une valeur par défaut appropriée
    }
}


std::map<int, std::vector<float>> Dico::getDicoMAP() {
    return DicoMAP;
}


const std::map<std::string, std::vector<float>> Dico::getDicocomm() {
    return Dicocomm;
}

std::map<std::string, std::vector<float>> Dico::getDicoinstru() {
    return Dicoinstru;
}

std::map<int, const char *> Dico::getDicovoix() {
    return Voix;
}




std::string Dico::checkinstru(float freq, const std::map<std::string, std::vector<float>>& dictionary) {
        std::string key = ""; // Initialiser la clé à une chaîne vide

        // Parcourir le dictionnaire
        for (const auto& entry : dictionary) {
            // Récupérer les valeurs min et max de la fréquence de la ligne actuelle
            float minFreq = entry.second[0]; // Valeur de la colonne 2 (minimum)
            float maxFreq = entry.second[1]; // Valeur de la colonne 3 (maximum)

            // Vérifier si la fréquence donnée se trouve entre minFreq et maxFreq
            if (freq >= minFreq && freq <= maxFreq) {
                key = entry.first; // Stocker la clé actuelle
                break; // Sortir de la boucle une fois qu'une correspondance est trouvée
            }
        }

        return key;
    }
