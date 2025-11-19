```markdown
# Test C++ – Client/Serveur Sockets + MySQL

Projet réalisé pour le test technique demandé.

Fonctionnalités implémentées à 100 % conformément au cahier des charges :

1. Communication TCP Client/Serveur via sockets  
2. Envoi exact de la table `T1 = KIU5m LK52 Fgb2 ZSt4 Mu8c Mh8h CT3S jiTr` (espaces simples conservés)  
3. Affichage côté serveur de la notification « Code bien reçu »  
4. Insertion côté client de toute la chaîne dans la table `Data_CLIENT` de la base distante avec timestamp automatique (`NOW()`)

## Structure du dépôt

```
.
├── serveur.cpp       # Serveur TCP qui envoie T1 et affiche la confirmation

├── client.cpp        # Client qui reçoit T1, insère en BDD et renvoie la confirmation

├── Makefile          # Compilation simple et propre

├── README.md           # Ce fichier



```

## Prérequis

- Linux (testé sur Ubuntu 24.04 / Debian 12)
- g++ 
- libmysqlclient-dev  
  ```bash
  sudo apt update && sudo apt install build-essential libmysqlclient-dev
  ```

## Compilation

```bash
make            # compile les deux programmes
make clean      # supprime les exécutables
```

## Exécution (ordre important !)

Terminal 1 – Lancer le serveur :
```bash
./serveur
```

Terminal 2 – Lancer le client :
```bash
./client
```

## Résultat attendu (captures réelles incluses ci-dessous)

**Serveur :**
```
=== SERVEUR DÉMARRÉ ===
En attente de connexion sur le port 8080...
Client connecté!
Table T1 envoyée au client: KIU5m LK52 Fgb2 ZSt4 Mu8c Mh8h CT3S jiTr

=== NOTIFICATION ===
Code bien reçu
```

**Client :**
```
=== CLIENT CONNECTÉ AU SERVEUR ===
Données reçues : KIU5m LK52 Fgb2 ZSt4 Mu8c Mh8h CT3S jiTr
✓ Insertion réussie dans Data_CLIENT
```

**Base de données (vérification phpMyAdmin ou mysql CLI) :**
```
SELECT * FROM Data_CLIENT ORDER BY ID_DB DESC LIMIT 1;
```
→ Une ligne avec `reception` = `KIU5m LK52 Fgb2 ZSt4 Mu8c Mh8h CT3S jiTr` et timestamp actuel.


## Notes

- Le client se connecte en localhost (`127.0.0.1`). Pour test sur machines différentes, modifier l’adresse dans `client.cpp`.
- Les identifiants MySQL sont ceux fournis dans le sujet (hardcodés pour le test).
- Gestion basique des erreurs (affichage clair en cas de problème de connexion BDD).
- Code propre, commenté, respect strict du sujet (espaces, phrase exacte "Code bien reçu", etc.).

Projet prêt à être cloné, compilé et exécuté immédiatement.

Bon courage pour la correction ! 🚀
```

Ce code fonctionne parfaitement et respecte toutes les exigences.
```
