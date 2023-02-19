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
#include "pf/GameCommand.hpp"
#include "pf/GameObject.hpp"
#include "pf/ZombieMoveAttack.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <thread> //for typeText function
#include <chrono> //for typeText function
 // to access windows library for color used
using namespace std;

void typeText(string text,int speed) 
{
    for (char character : text) {
        cout << character;
        std::this_thread::sleep_for(std::chrono::milliseconds(speed)); // Add a delay of time milliseconds between each character
    }
}

int main()
{
    pf::ClearScreen();
    typeText("Welcome to 'Alien vs Zombie'!\n\n",40);
    typeText("In this game, you play as a commander who must guide an advanced alien named Airen through a post-apocalyptic world overrun by zombies.\n\n",40);
    typeText("Your mission is to use Airen's advanced technology and fighting skills to defeat the hordes of undead and protect the remaining human survivors.\n\n",40);
    typeText("Are you ready to lead Airen to victory and become humanity's savior? Let the battle begin!\n\n",40);
    pf::Pause();
    char again = 'Y';
    while (again == 'y' || again == 'Y')
    {
        pf::ClearScreen();
        srand(time(NULL));
        GameSetting setting; // for game setting
        setting.Main_GameSetting(); // game setting to set row,columns and zombie number
        pf::Pause();                // press any key to continue
        Alien A;                    // for character Alien
        Zombie zombie;              // for all character Zombie
        GameBoard gameboard;
        A.CreateAlien(100, 0);                // create alien with int life=100,and int attack = 0
        zombie.CreateMultipleZombie(setting); // create the zombie depends on columns,rows and number of zombie

        pf::ClearScreen();
        gameboard.init(setting); // object placed in gameboard random
        A.land(gameboard);       // Alien show in gameboard
        zombie.land(gameboard);  // zombie show in gameboard

        bool AlienVsZombie = true;
        while (AlienVsZombie)
        {
            // alien turn
            bool alien_command = true;
            while (alien_command)
            {
                pf::ClearScreen();
                // show gameboard and attributes
                gameboard.displayGameBoard();
                A.AlienTurn();
                A.display();      // display Alien Attributes
                zombie.display(); // display Zombie Attributes
                // alien command
                string command;
                cout << endl
                     << "command > ";
                cin >> command;
                if (command == "up") // alien move up
                {
                    A.A_up(gameboard, zombie);
                    alien_command = false;
                    cout << endl;
                    pf::Pause();
                    pf::ClearScreen();
                    gameboard.displayGameBoard();
                    A.AlienTurn();
                    A.display();      // display Alien Attributes
                    zombie.display(); // display Zombie Attributes
                    cout << endl
                         << "Alien's turn ends. The trail is reset." << endl;
                }
                else if (command == "down") // alien move down
                {
                    A.A_down(gameboard, zombie);
                    alien_command = false;
                    cout << endl;
                    pf::Pause();
                    pf::ClearScreen();
                    gameboard.displayGameBoard();
                    A.AlienTurn();
                    A.display();      // display Alien Attributes
                    zombie.display(); // display Zombie Attributes
                    cout << endl
                         << "Alien's turn ends. The trail is reset." << endl;
                }
                else if (command == "left") // alien move left
                {
                    A.A_left(gameboard, zombie);
                    alien_command = false;
                    cout << endl;
                    pf::Pause();
                    pf::ClearScreen();
                    gameboard.displayGameBoard();
                    A.AlienTurn();
                    A.display();      // display Alien Attributes
                    zombie.display(); // display Zombie Attributes
                    cout << endl
                         << "Alien's turn ends. The trail is reset." << endl;
                }
                else if (command == "right") // alien move right
                {
                    A.A_right(gameboard, zombie);
                    alien_command = false;
                    cout << endl;
                    pf::Pause();
                    pf::ClearScreen();
                    gameboard.displayGameBoard();
                    A.AlienTurn();
                    A.display();      // display Alien Attributes
                    zombie.display(); // display Zombie Attributes
                    cout << endl
                         << "Alien's turn ends. The trail is reset." << endl;
                }
                else if (command == "arrow") // change arrow direction
                {
                    COMMAND::arrow(gameboard);
                }
                else if (command == "help") // show help command
                {
                    COMMAND::help();
                }
                else if (command == "save") // save the game
                {
                    COMMAND::save(setting, gameboard, zombie, A);
                }
                else if (command == "load") // load the game
                {
                    COMMAND::load(setting, gameboard, zombie, A);
                }
                else if (command == "quit")
                {
                    COMMAND::quit_game();
                }
                else
                {
                };

                // board border &Trail reset
                pf::Pause();
                gameboard.reset(setting);            // trail reset
                A.attack_reset();                    // alien attack reset
                AlienVsZombie = zombie.zombieLose(); // if all zombie life=0,alien win

                // for testing
                /*gameboard.displayGameBoard();
                A.display();
                zombie.display();*/
            }

            if (AlienVsZombie == false)
            {
                break;
            }

            ZombieMovement zombiemovement;
            bool zombie_turn = true;
            while (zombie_turn)
            {
                for (int i = 1; i <= setting.getZombieNumber(); ++i)
                {
                    if (zombie.GetZombieLife(i) <= 0)
                    {
                        continue;
                    }
                    else
                    {
                        pf::ClearScreen();
                        gameboard.displayGameBoard();
                        zombie.ZombieTurn(i);
                        A.display();
                        zombie.display();
                        cout << endl;
                        zombiemovement.Zombie_move(gameboard, zombie, i);
                        pf::Pause();
                        pf::ClearScreen();
                        gameboard.displayGameBoard();
                        zombie.ZombieTurn(i);
                        A.display();
                        zombie.display();
                        zombiemovement.Zombie_Found_Attack_Alien(gameboard, zombie, A, i);
                        pf::Pause();
                        pf::ClearScreen();
                        gameboard.displayGameBoard();
                        zombie.ZombieTurn(i);
                        A.display();
                        zombie.display();
                        
                    }
                }
                cout<<"\nZombie turns end"<<endl;
                pf::Pause();
                AlienVsZombie = A.AlienLose();
                zombie_turn = false;
            }
        }
        cout<<"\nPlay again(y/n):";
        cin >> again;
    }
    cout<<"\nThank you for playing !"<<endl; 
    typeText(" _____   _   _    ___    _   _   _   __   __   __  _____   _   _\n",5);
    typeText("|_   _| | | | |  / _ \\  | \\ | | | | / /   \\ \\ / / |  _  | | | | |\n",5);
    typeText("  | |   | |_| | / /_\\ \\ |  \\| | | |/ /     \\ V /  | | | | | | | |\n",5);
    typeText("  | |   |  _  | |  _  | | . ` | |    \\      \\ /   | | | | | | | |\n",5);
    typeText("  | |   | | | | | | | | | |\\  | | |\\  \\     | |   \\ \\_/ / | |_| |\n",5);
    typeText("  \\_/   \\_| |_/ \\_| |_/ \\_| \\_/ \\_| \\_/     \\_/    \\___/   \\___/ \n",5);
}  