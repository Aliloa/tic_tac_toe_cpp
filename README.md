# Execution du programme:
g++ main.cpp -o tic_tac_toe

Aucune bibliothèque externe n’est nécessaire.

## Organisation du code

- main.cpp : point d’entrée du programme, gestion de la boucle principale du jeu
- player.cpp et payer.hpp : contiennent les fonctins pour l'initialization du personnage
- game.cpp : contient toutes les fonctions de logique de jeu

### Améliorations

- IA intélligente (détection de possibilité de gagner, détection de possibiliter de bloquer)
- Couleurs dans le terminal et joli mise en page (avec des chargement et ascii art)
- On peut taper help pour visualiser les possibilités

#### Problèmes rencontrés

- J'ai voulu implémenter une interface UI avec Raylib mais après des recherches je me suis rendue compte que ça allait me prendre trop de temps alors j'ai décidé de simplement ajouter des couleurs dans le terminal. (j'ai aussi teste imgui mais encore ça m'aurait pris trop de temps)

- J'ai eu du mal à gérer les espaces dans le terminal le getline cassait tout par la suite, mais j'ai réussi à trouver la solution avec : 
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
