#include <iostream>
#include <limits>
#include "Player.hpp"

Player createPlayer(int p)
{
    std::cout << "=== CREATEUR DE PERSONNAGE " << p << " ===" << std::endl;

    Player player;

    std::cout << "Entrez le nom du joueur : ";
    std::getline(std::cin, player.name);

    if (p == 1)
    {
        while (true)
        {
            std::cout << "Choisissez votre symbole (x ou o) : ";
            std::cin >> player.symbol;
            player.symbol = std::tolower(player.symbol);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (player.symbol == 'x' || player.symbol == 'o')//vérification si c'est le bon symbole
            {
                break;
            }
            std::cout << "Erreur : entrez seulement 'x' ou 'o'" << std::endl;
        }
    }
    std::cout << "=== PERSONNAGE" << p << " CREE ===" << std::endl;
    std::cout << "Nom : " << player.name << std::endl;
    std::cout << "Symbole : " << player.symbol << std::endl;
    return player;
}
