#include <iostream>
#include <limits>
#include "player/Player.hpp"
#include "game/Game.hpp"

enum GameMode
{
    multiplayer,
    ai
};

GameMode select_mode()
{
    std::cout << "=== SELECTIONNER UN MODE ===" << std::endl;
    std::cout << "1-multiplayer ou 2-ia : ";
    char choix = {0};
    while (true)
    {
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choix == '1' || choix == '2') // verification si c bien une valeur attendue
        {
            break;
        }
        std::cout << "Erreur : entrez seulement '1' ou '2'" << std::endl;
    }
    if (choix == '1')
    {
        std::cout << "=== JOUEUR VS JOUEUR ===" << std::endl;

        return GameMode::multiplayer;
    }
    else
    {
        std::cout << "=== JOUEUR VS IA === " << std::endl;
        return GameMode::ai;
    }
}

int main()
{
    GameMode mode = select_mode();
    Player p1 = createPlayer(1);

    Player p2;
    if (mode == multiplayer)
    {
        p2 = createPlayer(2);
    }
    else
    {
        p2.name = "AI";
    }
    p2.symbol = (p1.symbol == 'x') ? 'o' : 'x';

    Player players[2] = {p1, p2};

    for (int i = 0; i < 9; i++)
    {
        Player current_player = players[i % 2]; // on alterne entre 0 et 1 pour les valeurs du tableau pour switch les tours
        int result;

        if (mode == GameMode::ai && current_player.symbol == p2.symbol)
        {
            ai_play(current_player);
        }
        else
        {
            do
            {
                result = play(current_player);
                if (result == 1)
                    std::cout << "cette case est deja prise" << std::endl;
            } while (result != 0);
        }

        draw_game_board(board);
        char winner = check_win();
        if (winner != '.')
        {
            std::cout << "Le joueur " << current_player.name << " a gagne !" << std::endl;
            break;
        }
    }
    if (check_win() == '.')
    {
        std::cout << "Match nul !" << std::endl;
    }
    return 0;
}