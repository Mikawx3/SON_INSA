A Particular MIDI Synthesizer

Installation :

Pour installer ce projet, suivez ces étapes :

Connectez le Teensy à un ordinateur via un câble USB.
Assurez-vous d'avoir un micro et une sortie audio connectés à l'ordinateur.
Utilisez une carte SD contenant les fichiers vocaux nécessaires pour l'interaction avec l'utilisateur.

Utilisation :

Pour démarrer, commencez par jouer la note DO4 pour initier la composition des notes. Suivez ensuite les instructions données par l'assistant vocal pour ajouter d'autres notes à votre composition. Une fois la composition terminée, vous aurez le choix parmi plusieurs instruments pour la synthèse des sons.

Après avoir joué les notes, trois commandes sont disponibles : vous pouvez choisir de rejouer le même morceau, de changer l'instrument utilisé, ou de recommencer à zéro pour créer une nouvelle composition.

Structure du Projet :

Le projet est développé en C++ à l'aide de l'environnement Arduino, qui offre diverses bibliothèques telles que audio.h pour la gestion des sons. L'algorithme clé du projet est la fonction notefreq, basée sur l'algorithme YIN pour la reconnaissance de fréquences. Ce code est écrit et géré dans l'environnement de développement Arduino, et il est spécifiquement conçu pour fonctionner sur le microcontrôleur Teensy.

La synthèse des sons est réalisée à partir d'un fichier compilé créé sur FaustIDE, un environnement de développement pour la programmation audio et le traitement du signal. Les voix de l'assistant vocal sont stockées sur une carte SD, avec différents fichiers audio utilisés pour l'interaction avec l'utilisateur.

Explication des sources: 

Les fichiers synth.cpp et synth.h sont des fichiers générés à partir de Faust pour la synthèse sonore d'une guitare et d'une flûte. Ils définissent une classe Synth utilisée pour la gestion du signal audio et MIDI, adaptée à la plateforme Teensy.

Le fichier dico.h définit une classe Dico qui gère des correspondances entre des fréquences et des informations sur les notes de musique, les instruments, les voix et les commandes. Les méthodes incluent la vérification des instruments et des voix associées à une fréquence donnée, ainsi que la récupération de différents dictionnaires contenant ces informations.

Le fichier dico.cpp fournit les définitions de ces méthodes, notamment la recherche de correspondances de fréquence dans les dictionnaires et la récupération des données associées.

Ces fichiers sont utilisés pour gérer les données de fréquence et les correspondances associées à des instruments de musique, des voix et des commandes dans un système logiciel.


Le fichier recorder.h définit une classe Recorder qui gère l'enregistrement et la lecture de séquences de notes jouées. La classe contient des méthodes pour ajouter des notes jouées, vérifier si une séquence est terminée, jouer les notes enregistrées, effacer les enregistrements, et convertir des caractères en chaînes de caractères. De plus, il y a une méthode pour gérer les commandes telles que "replay", "other_instru", "an other one", et "normal mode".

Le fichier recorder.cpp fournit les implémentations de ces méthodes, y compris la logique pour jouer les notes enregistrées et gérer les commandes.

Ces fichiers sont utilisés pour enregistrer, manipuler et jouer des séquences de notes dans un système logiciel.

Le fichier setup.ino contient le code Arduino pour initialiser le système audio et les composants matériels, ainsi que pour gérer l'enregistrement et la lecture des séquences de notes.

Le code initialise les composants audio et configure les connexions entre eux à l'aide de la bibliothèque Audio. Il initialise également les objets de classe Synth, Dico et Recorder.

Dans la fonction setup(), le code configure les paramètres audio, récupère les dictionnaires contenant les informations sur les notes, les instruments, les commandes et les voix à partir de la classe Dico, et initialise la communication avec la carte SD pour la lecture des fichiers audio.

Dans la fonction loop(), le code vérifie en continu les fréquences détectées par le système audio et agit en conséquence. Il enregistre les notes jouées, détermine si une séquence est terminée, joue les notes enregistrées, et gère les commandes vocales pour choisir des instruments, rejouer les séquences enregistrées ou effectuer d'autres actions.

Le code gère également des états tels que l'ouverture et la fermeture de la séquence, le choix d'instruments, la lecture de séquences enregistrées, etc.

En résumé, ce fichier contient le code de configuration et de gestion du système audio pour enregistrer, manipuler et jouer des séquences de notes dans un environnement Arduino.

Configuration :

Vous avez la possibilité d'ajouter de nouveaux instruments de deux manières :

Via Faust : Vous pouvez créer un nouveau fichier Faust pour synthétiser de nouveaux instruments. Ensuite, vous pouvez associer ces instruments à la classe Synth et les intégrer dans votre projet en mettant à jour les bibliothèques nécessaires.

En codant en C++ : Alternativement, vous pouvez coder de nouveaux instruments directement en C++. Vous pouvez ensuite les associer à la classe Synth et modifier les dictionnaires présents dans le fichier dico.h pour les inclure.

En outre, vous pouvez ajuster le seuil de détection des fréquences dans le fichier dico.h pour mieux correspondre à vos besoins. De plus, vous avez la possibilité de modifier les voix de l'assistant vocal en ajoutant ou en modifiant les fichiers audio stockés sur la carte SD.

Ces options vous offrent une flexibilité pour personnaliser votre projet en ajoutant de nouveaux instruments, en ajustant les paramètres de détection des fréquences et en modifiant les voix de l'assistant vocal selon vos préférences.

Contributions :

Vous pouvez contribuer en aidant à la synthèse des différents sons et à la gestion des commandes.

Auteurs :

Mahamat Tahir Saleh

Ounissi Mikail

Naym Houssam (arrivé en cours de route)

Remerciements :

Nous tenons à remercier nos instructeurs qui nous ont accompagnés tout au long du projet :

Romain Michon (Inria)
Tanguy Risset (INSA Lyon)

Contact :

Pour toute question ou suggestion, veuillez nous contacter :

Mikail Ounissi : mikail.ounissi@insa-lyon.fr

Mahamat Tahir Saleh : tahir.mahamat-saleh@insa-lyon.fr

Houssam Naym : houssam.naym@insa-lyon.fr
