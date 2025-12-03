#include <iostream>
#include "Player.hpp"

Player createPlayer()
{
    Player player;

    std::cout << "Entrez le nom du joueur : ";
    std::getline(std::cin, player.name);

    while (true)
    {
        std::cout << "Choisissez votre symbole (x ou o) : ";
        std::cin >> player.symbol;
        if (player.symbol == 'x' || player.symbol == 'o')
        {
            break;
        }
        std::cout << "Erreur : entrez seulement 'x' ou 'o'\n";
        std::cin.clear();
    }

    return player;
}
