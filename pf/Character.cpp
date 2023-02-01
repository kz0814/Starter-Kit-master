#include <iostream>
#include <vector>
#include <iomanip> //for setw()
#include "Character.hpp"
#include "Gamesetting.hpp"
using namespace std;

void Alien::CreateAlien(int life, int attack) // create Allien with life and attack
{
    AlienLife_ = life;
    AlienAttack_ = attack;
}

void Alien::change_life(char Arimetric, int value) // change AlienLife/value by plus or minus(multiply and divide can be added)
{
    if (Arimetric == '+') // plus value
    {
        AlienLife_ += value;
    }
    else if (Arimetric == '-') // minus value
    {
        AlienLife_ -= value;
    }
    else
    {
    }
}

void Alien::change_attack(char Arimetric, int value) // change AlienLife/value by plus or minus(multiply and divide can be added)
{
    if (Arimetric == '+') // plus value
    {
        AlienAttack_ += value;
    }
    else if (Arimetric == '-') // minus value
    {
        AlienAttack_ -= value;
    }
    else
    {
    }
}

void Alien::display()
{
    cout << setw(8) << "Alien" << setw(5) << ":" << setw(5)
         << "Life" << setw(5) << GetAlienLife() << ", "
         << "Attack" << setw(5) << GetAlienAttack()
         << endl;
}

void Alien::land(GameBoard &gameboard)
{
    X_ = (gameboard.getDimX() + 1) / 2;
    Y_ = (gameboard.getDimY() + 1) / 2;
    gameboard.setObject(X_, Y_, 'A');
}

vector<int> Zombie::PossibleRange()
{
    vector<int> range;

    if (dimX_ > dimY_)
    {
        for (int i = 1; i <= dimY_; ++i)
        {
            range.push_back(i);
        }
        range.resize(dimY_);
    }
    else
    {
        for (int i = 1; i <= dimX_; ++i)
        {
            range.push_back(i);
        }
        range.resize(dimX_);
    }

    return range;
}

void Zombie::CreateZombie()
{ // Possible Life ,Possible Attack and Possible range
    int PossibleLife[] = {100, 125, 150, 175, 200, 225, 250, 275, 300};
    int PossibleAttack[] = {5, 10, 15, 20, 25, 30};
    vector<int> Possiblerange = PossibleRange(); 

    int Life = PossibleLife[rand() % 9];                      // 9 possible Life
    int Attack = PossibleAttack[rand() % 6];                  // 6 possible attack
    int Range = Possiblerange[rand() % Possiblerange.size()]; // possible range size depend on the vector Possiblerange

    Life_.push_back(Life);
    Attack_.push_back(Attack);
    Range_.push_back(Range);
}

void Zombie::CreateMultipleZombie(GameSetting &setting)
{
    setvalue(setting);
    for (int i = 0; i < ZombieNumber_; ++i)
    {
        rand();
        CreateZombie();
    }
}

void Zombie::change_life(int sequence_number, char Arimetric, int value)
{
    if (Arimetric == '+')
    {
        Life_[sequence_number - 1] += value;
    }
    else if (Arimetric == '-')
    {
        Life_[sequence_number - 1] -= value;
    }
}

void Zombie::display()
{
    for (int i = 0; i < ZombieNumber_; ++i)
    {
        cout << setw(9) << "Zombie" << setw(2) << i + 1 << " : "
             << "Life " << setw(4) << Life_[i] << ", "
             << "Attack " << setw(4) << Attack_[i] << ", "
             << "Range " << setw(3) << Range_[i] << endl;
    }
}

void Zombie::land(GameBoard &gameboard)
{
    char number = '1';
    for (int i = 0; i < ZombieNumber_; i++)
    {
        bool run = true;
        int current_x;
        int current_y;
        X_.push_back(current_x);
        Y_.push_back(current_y);
        while (run)       
        {
            current_x = rand() % gameboard.getDimX()+1 ;
            current_y = rand() % gameboard.getDimY()+1 ;
            
            if (current_x == ((gameboard.getDimX() + 1) / 2) && current_y == ((gameboard.getDimY() + 1) / 2))
            {
            }
            else
            {
                run=false;
                for (int j = 0; j < i+1; j++)
                {
                    if (current_x == X_[j] && current_y == Y_[j])
                    {
                        run= true;
                        break;
                    }
                        run = false;
                }
            }
        }
        gameboard.setObject(current_x, current_y, number);
        number = number + 1;
    }
}
