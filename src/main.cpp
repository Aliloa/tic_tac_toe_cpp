#include <iostream>
#include <limits>
#include "player/Player.hpp"
#include "game/Game.hpp"

// esthetique
#define RESET "\033[0m"
#define BOLD "\033[1m"

#define RED "\x1b[38;5;210m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

#define PINK_LIGHT "\x1b[38;5;225m" // rose clair vif
#define PINK "\x1b[38;5;212m"       // rose doux / dim

#define LEAF_GREEN "\x1b[38;5;122m" // vert feuille
#define SKY_BLUE "\x1b[38;5;159m"   // ciel léger

#include <thread>
#include <chrono>

void clearScreen()
{
    std::cout << "\033[2J\033[H";
}

void loading()
{
    std::cout << SKY_BLUE << "Chargement";
    for (int i = 0; i < 3; i++)
    {
        std::cout << ".";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
    std::cout << RESET << "\n";
}

void ai_thinking()
{
    std::cout << SKY_BLUE << "...reflexion";
    for (int i = 0; i < 3; i++)
    {
        std::cout << ".";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
    std::cout << RESET << "\n";
}

enum GameMode
{
    multiplayer,
    ai
};

GameMode select_mode()
{
    loading();
    clearScreen();

    std::cout << LEAF_GREEN << "------------------------------------" << std::endl;
    std::cout << PINK << " _____ _        _____            _____          " << std::endl;
    std::cout << PINK << "|_   _(_) ___  |_   _|_ _  ___  |_   _|__   ___ " << std::endl;
    std::cout << PINK << "  | | | |/ __|   | |/ _` |/ __|   | |/ _ \\ / _ \\" << std::endl;
    std::cout << PINK << "  | | | | (__    | | (_| | (__    | | (_) |  __/" << std::endl;
    std::cout << PINK << "  |_| |_|\\___|   |_|\\__,_|\\___|   |_|\\___/ \\___|" << std::endl;

    std::cout << LEAF_GREEN << "------------------------------------" << std::endl;

    loading();
    std::cout << LEAF_GREEN << "------------------------------------" << std::endl;

    std::cout << PINK << "         - MODE DE JEU -          " << std::endl;
    std::cout << RESET << std::endl;

    std::cout << LEAF_GREEN << "  [1] " << PINK << "JOUEUR VS JOUEUR" << std::endl;
    std::cout << LEAF_GREEN << "  [2] " << PINK << "JOUEUR VS IA" << std::endl;
    std::cout << PINK_LIGHT << "-> Choix : " << RESET;
    char choix = {0};
    while (true)
    {
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choix == '1' || choix == '2') // verification si c bien une valeur attendue
        {
            break;
        }
        std::cout << RED << "XX Erreur : entrer 1 ou 2 -> " << RESET;
    }
    if (choix == '1')
    {
        std::cout << PINK << "Mode selectionne: " << LEAF_GREEN << "JOUEUR VS JOUEUR" << RESET << std::endl;
        loading();
        clearScreen();

        return GameMode::multiplayer;
    }
    else
    {
        std::cout << PINK << "Mode selectionne: " << LEAF_GREEN << "JOUEUR VS IA" << RESET << std::endl;
        loading();
        clearScreen();
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
    std::cout << YELLOW << "Astuce : tapez" << SKY_BLUE << " help " << YELLOW << "pour avoir de l'aide" << std::endl;

    for (int i = 0; i < 9; i++)
    {
        Player current_player = players[i % 2]; // on alterne entre 0 et 1 pour les valeurs du tableau pour switch les tours
        int result;

        if (mode == GameMode::ai && current_player.symbol == p2.symbol)
        {
            ai_thinking();
            ai_play(current_player);
        }
        else
        {
            do
            {
                result = play(current_player);
                if (result == 1)
                    std::cout << RED << "cette case est deja prise" << std::endl;
            } while (result != 0);
        }

        draw_game_board(board);
        char winner = check_win();
        if (winner != '.')
        {
            std::cout << LEAF_GREEN << "Le joueur " << PINK << current_player.name << LEAF_GREEN << " a gagne !" << PINK << " \\ (^_^) /" << std::endl;
            break;
        }
    }
    if (check_win() == '.')
    {
        std::cout << LEAF_GREEN << "Match nul ! (X_X)" << std::endl;
    }
    return 0;
}