#include <iostream>
#include <limits>
#include "Player.hpp"

Player createPlayer(int p)
{
    Player player;

    std::cout << "Entrez le nom du joueur : ";
    std::getline(std::cin, player.name);

    if (p == 1)
    {
        while (true)
        {
            std::cout << "Choisissez votre symbole (x ou o) : ";
            std::cin >> player.symbol;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (player.symbol == 'x' || player.symbol == 'o')
            {
                break;
            }
            std::cout << "Erreur : entrez seulement 'x' ou 'o'\n";
        }
    }

    return player;
}
