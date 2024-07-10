# 🎮 Jeu du Pendu

Ce projet implémente un jeu du pendu en ligne de commande. Le joueur doit deviner un mot choisi aléatoirement parmi une liste de mots. Le mot est partiellement révélé au début avec la première et la dernière lettre affichées, et le joueur a un nombre limité d'essais pour deviner le mot complet.

## 🛠️ Prérequis

- `gcc` : Compilateur GNU.
- `make` : Outil de construction.

## 💻 Installation

### Sous Windows avec Cygwin

Assurez-vous que vous avez installé Cygwin avec les paquets `gcc-core`, `make`.

### Sous Windows avec WSL

1. Installez WSL (Windows Subsystem for Linux) et une distribution Linux comme Ubuntu :
   - Ouvrez PowerShell en tant qu'administrateur et exécutez :
     ```powershell
     wsl --install -d Ubuntu
     ```
   - Redémarrez votre ordinateur si nécessaire.
   - Ouvrez Ubuntu à partir du menu Démarrer de Windows et suivez les instructions de configuration initiale.


## ⚙️ Compilation

1. Clonez ce dépôt ou téléchargez les fichiers source dans un répertoire de votre choix.
2. Ouvrez un terminal et naviguez vers le répertoire du projet.
3. Exécutez les commandes suivantes pour compiler le projet :
   ```sh
      make clean
      make

## ▶️ Exécution
Après avoir compilé le projet, exécutez le jeu avec la commande suivante :

      ./pendu

## 📜 Règles du Jeu

1. Le jeu commence par révéler la première et la dernière lettre du mot à deviner.
2. Le joueur doit deviner les lettres restantes du mot en entrant une lettre à la fois.
3. Le joueur a un nombre limité d'essais (6 essais maximum).
4. Chaque mauvaise tentative dessine progressivement le pendu.
5. Le jeu se termine lorsque le joueur devine correctement le mot ou lorsque le pendu est entièrement dessiné.


## 📚 Exemple de mots utilisés
Le jeu utilise les mots suivants pour les devinettes :

         char *mots[] = {
            "abricot", "brouhaha", "cacahuète", "dingue", "farfelu",
            "goupil", "hippopotame", "igloo", "jaloux", "kangourou",
            "limace", "marmotte", "nincompoop", "ouistiti", "pamplemousse",
            "quinoa", "ratatouille", "sapristi", "trombone", "utopiste"
         };


## 🛡️ Vérification des Fuites de Mémoire

Pour vérifier les fuites de mémoire avec Valgrind (uniquement sous WSL), exécutez la commande suivante :

         valgrind --leak-check=full ./pendu

## Auteur

- [@LeonardBEN](https://github.com/LeonardBen)
- [@elizblt](https://github.com/elizblt)
- [@NicolasDS](https://github.com/SynhPoO)