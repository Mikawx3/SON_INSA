A Particular MIDI Synthesizer

Installation :

Pour installer ce projet, connectez le Teensy à un ordinateur via un câble USB. Assurez-vous d'avoir un micro et une sortie audio connectés à l'ordinateur et d'une carte SD avec les fichiers vocaux nécessaire.

Utilisation :

Pour démarrer, commencez par jouer la note DO4 pour initier la composition des notes. Suivez ensuite les instructions données par l'assistant vocal pour ajouter d'autres notes à votre composition. Une fois la composition terminée, vous aurez le choix parmi plusieurs instruments pour la synthèse des sons.

Après avoir joué les notes, trois commandes sont disponibles : vous pouvez choisir de rejouer le même morceau, de changer l'instrument utilisé, ou de recommencer à zéro pour créer une nouvelle composition.

Structure du Projet :

Le projet est développé en C++ à l'aide de l'environnement Arduino, qui offre diverses bibliothèques telles que audio.h pour la gestion des sons. L'algorithme clé du projet est la fonction notefreq, basée sur l'algorithme YIN pour la reconnaissance de fréquences. Ce code est écrit et géré dans l'environnement de développement Arduino, et il est spécifiquement conçu pour fonctionner sur le microcontrôleur Teensy.

La synthèse des sons est réalisée à partir d'un fichier compilé créé sur FaustIDE, un environnement de développement pour la programmation audio et le traitement du signal. Les voix de l'assistant vocal sont stockées sur une carte SD, avec différents fichiers audio utilisés pour l'interaction avec l'utilisateur.

Configuration :

Vous pouvez configurer de nouveaux instruments en créant un nouveau fichier permettant de les synthétiser via Faust, puis en mettant à jour les bibliothèques. Vous pouvez également paramétrer les sons détectables dans les différents dictionnaires, ainsi que les voix de l'assistant vocal stockées sur la carte SD.

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
