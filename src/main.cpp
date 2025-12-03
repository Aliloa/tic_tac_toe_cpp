#include <iostream>
#include "Player.hpp"

int main()
{
    std::cout << "=== CREATEUR DE PERSONNAGE ===\n\n";
    Player joueur = createPlayer();

    std::cout << "\n=== PERSONNAGE CREE ===\n";
    std::cout << "Nom : " << joueur.name << "\n";
    std::cout << "Symbole : " << joueur.symbol << "\n";
    return 0;
}