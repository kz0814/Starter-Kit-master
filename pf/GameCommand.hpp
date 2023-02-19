#ifndef PF_COMMAND_H
#define PF_COMMAND_H
#include <iostream>
#include "GameBoard.hpp"
#include "GameSetting.hpp"
#include "Character.hpp"

using namespace std;

namespace COMMAND
{
    void help();
    void arrow(GameBoard &gameboard);
    void save(GameSetting &gamesetting,GameBoard &gameboard,Zombie &zombie,Alien &alien);
    void load(GameSetting &gamesetting,GameBoard &gameboard,Zombie &zombie,Alien &alien);
    void quit_game();

    void split(string &String, vector<int> &Vector);
}

#endif

