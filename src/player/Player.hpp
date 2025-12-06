#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

struct Player
{
    std::string name;
    char symbol;
};

Player createPlayer(int p);

#endif