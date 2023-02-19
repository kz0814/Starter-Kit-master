#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <vector>
#include "Character.hpp"
#include "GameBoard.hpp"
using namespace std;


namespace GameObject //for the game objects
{
    void Health_();
    void Pod_(Zombie &zombie,GameBoard &gamboard,int x,int y); // x,y is pod location
    void Rock_(GameBoard &gameboard,int x,int y); // x,y is rock location
    
    bool Zombie_(Zombie &zombie,int sequence,int alien_attack);
};

#endif