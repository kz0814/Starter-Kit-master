// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: T10L
// Names: CHUA KAI ZHENG | LEE JIA MENG 
// IDs: 1211102409 | 1211102696 
// Emails: 1211102409@student.mmu.edu.my | 1211102696@student.mmu.edu.my 
// Phones: 01135578545 | 0168757963 
// *********************************************************

#include "pf/helper.h"
#include "pf/GameSetting.hpp"  
#include "pf/Character.hpp"
#include "pf/GameBoard.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
    cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl;

    srand(time(NULL));
    GameSetting setting;//for game setting

    setting.Main_GameSetting();//game setting to set row,columns and zombie number
    pf::Pause();//press any key to continue
    
    Alien A; //for character Alien
    Zombie zombie;//for all character Zombie
    GameBoard gameboard;
    A.CreateAlien(100,0);//create alien with int life=100,and int attack = 0
    zombie.CreateMultipleZombie(setting);//create the zombie depends on columns,rows and number of zombie

    pf::ClearScreen();
    gameboard.init(setting);
    A.land(gameboard);//Alien show in gameboard
    zombie.land(gameboard);//zombie show in gameboard
    gameboard.displayGameBoard();
    A.display();//display Alien Attributes
    zombie.display();//display Zombie Attributes
    zombie.display();
}