#include <iostream>
#include "Player.hpp"

char board[9] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};

int draw_game_board(char board[9])
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
            std::cout << "| ";

        std::cout << board[i] << " | ";

        if ((i + 1) % 3 == 0) // quand i+1 est divisble par 3
            std::cout << std::endl;
    }
    return 0;
}

int play(Player currentPlayer)
{
    std::cout << "Tour de " << currentPlayer.name << " : ";
    int value{};
    std::cin >> value;
    board[value - 1] = currentPlayer.symbol;
    return 0;
}

char check_win()
{
    int win_condition[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}};
    win_condition[1][2];
    for (int i = 0; i < 8; i++)
    {
        int a = win_condition[i][0];
        int b = win_condition[i][1];
        int c = win_condition[i][2];

        if (board[a] != '.' && board[a] == board[b] && board[a] == board[c])
        {
            std::cout << board[a] << "\n=== A GAGNE ===\n";

            return board[a];
        }
    }
    return '.';
}

int main()
{
    std::cout << "=== CREATEUR DE PERSONNAGE ===\n\n";
    Player p1 = createPlayer(1);

    std::cout << "\n=== PERSONNAGE CREE ===\n";
    std::cout << "Nom : " << p1.name << "\n";
    std::cout << "Symbole : " << p1.symbol << "\n";

    Player p2 = createPlayer(2);
    p2.symbol = (p1.symbol == 'x') ? 'o' : 'x';

    std::cout << "\n=== PERSONNAGE 2 CREE ===\n";
    std::cout << "Nom : " << p2.name << "\n";
    std::cout << "Symbole : " << p2.symbol << "\n";

    Player players[2] = {p1, p2};
    for (int i = 0; i < 9; i++)
    {
        Player current_player = players[i % 2];
        play(current_player);
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