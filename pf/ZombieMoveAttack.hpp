#ifndef ZOMBIEMOVEATTACK_H
#define ZOMBIEMOVEATTACK_H
#include <vector>
#include "Character.hpp"
#include "GameBoard.hpp"
using namespace std;

class ZombieMovement // for zombie's movement
{
public:
    bool Zombie_up(GameBoard &gameboard, Zombie &zombie, int sequence);
    bool Zombie_down(GameBoard &gameboard, Zombie &zombie, int sequence);
    bool Zombie_left(GameBoard &gameboard, Zombie &zombie, int sequence);
    bool Zombie_right(GameBoard &gameboard, Zombie &zombie, int sequence);
    void Zombie_move(GameBoard &gameboard, Zombie &zombie, int sequence);
    void Zombie_sound_attack();
    void Zombie_Found_Attack_Alien(GameBoard &gameboard, Zombie &zombie, Alien &alien, int sequence);
    
};

#endif