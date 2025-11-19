Projet Test C++ - Socket & MySQL

Ce projet répond aux exigences du test technique pour mettre en place une architecture client/serveur avec persistance de données dans une base MySQL distante.

Prérequis

Pour compiler ce projet sous Linux (Debian/Ubuntu), la librairie de développement MySQL est nécessaire :

sudo apt-get update
sudo apt-get install libmysqlclient-dev build-essential


Compilation

Utilisez le Makefile fourni pour compiler les deux exécutables :

make


Cela générera :

./serveur

./client

Exécution

Lancer le serveur dans un terminal :

./serveur


Lancer le client dans un autre terminal :

./client


Fonctionnalités implémentées

Communication Socket (TCP/IP) : Établie sur le port 8080.

Transfert de Données : La table T1 ("KIU5m", "LK52"...) est sérialisée et envoyée au client.

Base de Données : Le client se connecte à la base distante 188.165.236.167 et insère les données reçues dans Data_CLIENT.

Notification : Une fois l'insertion terminée, le client notifie le serveur qui affiche "Code bien reçu".

Preuve d'exécution (Exemple de log)

Côté Serveur :

=== SERVEUR DÉMARRÉ ===
En attente de connexion sur le port 8080...
Client connecté !
Données envoyées au client : KIU5m|LK52|Fgb2|ZSt4|Mu8c|Mh8h|CT3S|jiTr

=== NOTIFICATION ===
Code bien reçu
Message du client : Insertion effectuee avec succes


Côté Client :

=== CLIENT CONNECTÉ AU SERVEUR ===
Données T1 reçues : KIU5m|LK52|Fgb2|ZSt4|Mu8c|Mh8h|CT3S|jiTr
Connexion à la base de données réussie.
✓ Insertion réussie dans la table Data_CLIENT
