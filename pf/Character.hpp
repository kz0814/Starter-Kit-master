#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>
#include "GameSetting.hpp"
#include "GameBoard.hpp"
using namespace std;

class Alien //for Alien character
{
private:
int AlienLife_, AlienAttack_;//life and attack for alien
int X_,Y_;//coulumns and rows
public:
    // value
    // function
    void CreateAlien(int life,int attack); //create alien with life and attack
    void display(); //display alien life and attack
    void change_life(char Arimetric,int value);//to plus='+' or minus'-' alien life
    void change_attack(char Arimetric,int value);//to plus='+' or minus '-' alien attack
    void land(GameBoard &gameboard);

    // return value
    int GetAlienLife() const//get alien life
    {
        return AlienLife_;
    };
    int GetAlienAttack() const//get alien atack
    {
        return AlienAttack_;
    }

};


class Zombie //for zombie character
{
private:
    // value
    int dimX_, dimY_, ZombieNumber_; //row,columns and number of zombie
    
public:
    // value
    vector<int> Life_, Attack_, Range_;//vector value for all zombie created(exp Life_[0]=zombie 1 life,Life_[1]=zombie 2 life.......)
    vector<int> PossibleRange(); // get possible range for zombie and avoid more than maximun row/column
    vector<int> X_,Y_;//position for land
    // function
    void setvalue(GameSetting &setting)//set value depend on user input from Gamesetting 
    {
        dimX_ = setting.dimX_;
        dimY_ = setting.dimY_;
        ZombieNumber_ = setting.ZombieNumber_;
    };
    void CreateZombie();//one zombie create with life,attack,and range
    void CreateMultipleZombie(GameSetting &setting);//create multiple zombie with different of life,attack and range
    void change_life(int sequence_number,char Arimetric,int value);//plus='+' or minus='-' one of the zombie life with a value
    void display();//display all zombie life,attack and range
    void land(GameBoard &gameboard);
    

    // return value
    int GetZombieLife(int sequence_number) const // get one of the Zombie life
    {
        return Life_[sequence_number - 1];
    };
    int GetZombieAttack(int sequence_number) const // get one of the Zombie Attack
    {
        return Attack_[sequence_number - 1];
    };
    int GetZombieRange(int sequence_number) const// get one of the Zombie Range
    {
        return Range_[sequence_number - 1];
    };
    vector<int> ZombieInfo(int sequence_number, vector<int> Zombieinfo)//form a vector with allinfo of one of the Zombie {Life,Attack,Range}
    {
        Zombieinfo.push_back(Life_[sequence_number - 1]);
        Zombieinfo.push_back(Attack_[sequence_number - 1]);
        Zombieinfo.push_back(Range_[sequence_number - 1]);

        return Zombieinfo;
    }
    int GetZombieX(int sequence_number) const
    {
        return X_[sequence_number];
    }
    int GetZombieY(int sequence_number) const
    {
        return Y_[sequence_number];
    }
};


#endif
