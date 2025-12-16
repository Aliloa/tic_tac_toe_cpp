#include "Game.hpp"
#include <iostream>
#include <random>

#define RED "\x1b[38;5;210m"
#define GREEN "\033[32m"

#define PINK_LIGHT "\x1b[38;5;225m"    // rose clair vif
#define PINK "\x1b[38;5;212m"  // rose doux / dim
#define YELLOW "\033[33m"

#define LEAF_GREEN "\x1b[38;5;122m"   // vert feuille
#define SKY_BLUE "\x1b[38;5;159m"     // ciel léger

char board[9] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};

int draw_game_board(char board[9])
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
            std::cout << PINK << "| ";

        std::cout << SKY_BLUE << board[i] << PINK << " | ";

        if ((i + 1) % 3 == 0) // quand i+1 est divisble par 3
            std::cout << std::endl;
    }
    return 0;
}

void draw_help_board()
{
    std::cout << YELLOW << "| 1 | 2 | 3 |" << std::endl;
    std::cout << YELLOW << "| 4 | 5 | 6 |" << std::endl;
    std::cout << YELLOW << "| 7 | 8 | 9 |" << std::endl;
}

int play(Player currentPlayer)
{
    std::cout << SKY_BLUE << "-> Tour de " << PINK << currentPlayer.name << " : ";
    std::string input;
    std::cin >> input;
    for (char &c : input)
    {
        c = std::tolower(c);
    }
    if (input == "help")
    {
        draw_help_board();
        return 2;
    }
    int value = {};
    try
    {
        value = std::stoi(input);
    }
    catch (const std::invalid_argument &)
    {
        std::cout << RED << "valeur invalide." << std::endl;
        return 2;
    }

    if (value < 1 || value > 9)
    {
        std::cout << RED << "valeur invalide." << std::endl;
        return 2;
    }

    if (board[value - 1] == '.')
    {
        board[value - 1] = currentPlayer.symbol;
    }
    else
    {
        return 1;
    }
    return 0;
}

int ai_play(Player current_player)
{
    std::cout << SKY_BLUE << "Tour de : " << PINK << current_player.name << std::endl;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 8);
    int value = {};
    char p_symbol = (current_player.symbol == 'x') ? 'o' : 'x';
    value = ai_best_move(current_player.symbol, p_symbol);

    if (value == -1)//si l'ia ne peut ni gagner ni bloquer le joueur alors valeur aléatoire
    {
        do
        {
            value = distrib(gen);
        } while (board[value] != '.');
    }
    board[value] = current_player.symbol;
    return 0;
}
int win_condition[8][3] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6}};

char check_win()
{
    win_condition[1][2];
    for (int i = 0; i < 8; i++)
    {
        int a = win_condition[i][0];
        int b = win_condition[i][1];
        int c = win_condition[i][2];

        if (board[a] != '.' && board[a] == board[b] && board[a] == board[c])
        {
            return board[a];
        }
    }
    return '.';
}

int ai_best_move(char ai_symbol, char p_symbol)
{
    for (int i = 0; i < 8; i++)
    {
        int a = win_condition[i][0];
        int b = win_condition[i][1];
        int c = win_condition[i][2];

        //l'ia peut gagner?
        if (board[a] == ai_symbol && board[b] == ai_symbol && board[c] == '.') return c;
        if (board[a] == ai_symbol && board[c] == ai_symbol && board[b] == '.') return b;
        if (board[b] == ai_symbol && board[c] == ai_symbol && board[a] == '.') return a;

        //l'ia peut bloquer le joueur?
        if (board[a] == p_symbol && board[b] == p_symbol && board[c] == '.') return c;
        if (board[a] == p_symbol && board[c] == p_symbol && board[b] == '.') return b;
        if (board[b] == p_symbol && board[c] == p_symbol && board[a] == '.') return a;
    }
    return -1;
}