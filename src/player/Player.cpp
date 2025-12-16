#include <iostream>
#include <limits>
#include "Player.hpp"

#define PINK_LIGHT "\x1b[38;5;225m" // rose clair vif
#define PINK "\x1b[38;5;212m"  // rose doux / dim
#define RED "\x1b[38;5;210m"
#define LEAF_GREEN "\x1b[38;5;122m" // vert feuille

Player createPlayer(int p)
{
    std::cout << LEAF_GREEN << "------------------------------------" << std::endl;
    std::cout << PINK << "- PERSONNAGE" << p << " -" << std::endl;
    std::cout << LEAF_GREEN << "------------------------------------" << std::endl;

    Player player;

    std::cout << PINK_LIGHT << "-> Entrez le nom du joueur : ";
    std::getline(std::cin, player.name);

    if (p == 1)
    {
        while (true)
        {
            std::cout << PINK_LIGHT << "-> Choisissez votre symbole (x ou o) : ";
            std::cin >> player.symbol;
            player.symbol = std::tolower(player.symbol);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (player.symbol == 'x' || player.symbol == 'o') // vérification si c'est le bon symbole
            {
                break;
            }
            std::cout << RED << "Erreur : entrez seulement 'x' ou 'o'" << std::endl;
        }
    }

    std::cout << PINK_LIGHT << "- PERSONNAGE " << LEAF_GREEN << p << PINK_LIGHT << " CREE -" << std::endl;
    std::cout << PINK << "Nom : " << LEAF_GREEN << player.name << std::endl;
    if (p == 1)
    {
        std::cout << PINK << "Symbole : " << LEAF_GREEN << player.symbol << std::endl;
    }
    return player;
}
