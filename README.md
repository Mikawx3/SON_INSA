A Particular MIDI Synthesizer
Installation
Pour installer ce projet, connectez le Teensy à un ordinateur via un câble USB. Assurez-vous d'avoir un micro et une sortie audio connectés à l'ordinateur.

Utilisation
Pour commencer, composez la note DO4 pour initier la composition des notes. Suivez ensuite les instructions fournies par le Teensy tout au long du processus. Vous pouvez choisir parmi plusieurs instruments pour synthétiser les différents sons. À la fin de la composition, trois commandes sont possibles : rejouer le même morceau, changer d'instrument, ou recommencer à zéro.

Structure du Projet
Le projet est développé en C++ avec Arduino ou Visual Studio Code pour gérer les différents dictionnaires et méthodes, ainsi que pour la synthèse des sons sur FaustIDE. Le code est compilé et exécuté sur le Teensy. Le fichier setup.ino gère les interactions avec l'utilisateur et les différentes méthodes. Les voix de l'assistant vocal sont stockées sur une carte SD avec différents fichiers audio.

Configuration
Vous pouvez configurer de nouveaux instruments en créant un nouveau fichier permettant de les synthétiser via Faust, puis en mettant à jour les bibliothèques. Vous pouvez également paramétrer les sons détectables dans les différents dictionnaires, ainsi que les voix de l'assistant vocal stockées sur la carte SD.

Contributions
Vous pouvez contribuer en aidant à la synthèse des différents sons et à la gestion des commandes.

Auteurs
Mahamat Tahir Saleh
Ounissi Mikail
Naym Houssam (arrivé en cours de route)
Remerciements
Nous tenons à remercier nos instructeurs qui nous ont accompagnés tout au long du projet :

Romain Michon (Inria)
Tanguy Risset (INSA Lyon)
Contact
Pour toute question ou suggestion, veuillez nous contacter :

Mikail Ounissi : mikail.ounissi@insa-lyon.fr
Mahamat Tahir Saleh : tahir.mahamat-saleh@insa-lyon.fr
Houssam Naym : houssam.naym@insa-lyon.fr
