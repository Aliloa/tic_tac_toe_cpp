#ifndef GAME_HPP
#define GAME_HPP

#include "player/Player.hpp"

extern char board[9];

int draw_game_board(char board[9]);
void draw_help_board();
int play(Player currentPlayer);
char check_win();
int ai_play(Player currentPlayer);
int ai_best_move(char ai_symbol, char p_symbol);

#endif