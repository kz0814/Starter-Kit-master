#include <iostream>
#include <vector>
#include <iomanip> //for setw()
#include <numeric> // for accumulate() to find sum
#include "Character.hpp"
#include "Gamesetting.hpp"
#include "GameObject.hpp"
using namespace std;

//********Zombie
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
    //add or minus
    if (Arimetric == '+')
    {
        Life_[sequence_number - 1] += value;
    }
    else if (Arimetric == '-')
    {
        Life_[sequence_number - 1] -= value;
    }

    //min life is 0
    if (Life_[sequence_number-1] < 0)
    {
        Life_[sequence_number-1] = 0;
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
    int current_x = 0;
    int current_y = 0;
    for (int i = 0; i <= ZombieNumber_; i++)
    {
        if (i == ZombieNumber_)
        {
            X_.push_back(current_x);
            Y_.push_back(current_y);
        }
        else
        {
            bool run = true;
            X_.push_back(current_x);
            Y_.push_back(current_y);
            while (run)
            {
                current_x = rand() % gameboard.getDimX() + 1;
                current_y = rand() % gameboard.getDimY() + 1;

                if (current_x == ((gameboard.getDimX() + 1) / 2) && current_y == ((gameboard.getDimY() + 1) / 2))
                {
                }
                else
                {
                    run = false;
                    for (int j = 0; j < i + 1; j++)
                    {
                        if (current_x == X_[j] && current_y == Y_[j])
                        {
                            run = true;
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
}



void Zombie::zombieDied(GameBoard &gameboard)
{
    for (int i=1;i<=ZombieNumber_;++i)
    {
        int zombie_life=GetZombieLife(i);
        if (zombie_life == 0)
        {
            gameboard.setObject(GetZombieX(i),GetZombieY(i),' ');
        }
        else
        {

        }
    }
}

bool Zombie::zombieLose()
{
    int SumOfLife  = accumulate(Life_.begin(),Life_.end(),0);
    if (SumOfLife == 0)
    {
        system("cls");
        cout<<endl<<"Alien wins."<<endl
            <<"Congratulations, Alien save the word!"<<endl;
        return false;
    }  
    else
    {
        return true;
    }
}


//********Alien
void Alien::CreateAlien(int life, int attack) // create Allien with life and attack
{
    AlienLife_ = life;
    AlienAttack_ = attack;
}

void Alien::change_life(char Arimetric, int value) // change AlienLife/value by plus or minus(multiply and divide can be added)
{
    //add or minus life
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

    //makesure no more than 100 or less than 0
    if (AlienLife_ > 100) //more than 100 = 100
    {
        AlienLife_ = 100;
    }
    else if (AlienLife_ < 0)//less than 0 = 0
    {
        AlienLife_=0;
    }
    else
    {
    }


}

void Zombie::ZombieTurn(int sequence)
{
    cout<<"   Turn: Zombie "<<sequence<<'.'<<endl;
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

void Alien::A_left(GameBoard &gameboard,Zombie &zombie)
{
    bool movement = true;
    while (movement)
    {
        if (X_ > 1)
        {
            char object = gameboard.getObject(X_ - 1, Y_);
            next_object(movement, object,zombie,gameboard,X_ - 1, Y_);
            if (movement)
            {
                gameboard.setObject(X_, Y_, '.');
                X_ -= 1;
                gameboard.setObject(X_, Y_, 'A');
                cout<<endl;
                system("pause");
                system("cls");
                gameboard.displayGameBoard();
                AlienTurn();
                display();
                zombie.display();
                cout<<endl;
                if (object == 'v' || object == '<' || object == '>' || object == '^')
            {
                change_direction(object, gameboard,zombie);
                break;
            }
            }
        }
        else if (X_ == 1)
        {
            cout<<"Alien hits the border"<<endl;
            break;
        }
        else 
        {
            break;
        }
    }
}

void Alien::A_right(GameBoard &gameboard,Zombie &zombie)
{
    bool movement = true;
    while (movement)
    {
        if (X_ < gameboard.getDimX())
        {
            char object = gameboard.getObject(X_ + 1, Y_);
            next_object(movement, object,zombie,gameboard,X_+1,Y_);
            if (movement)
            {
                gameboard.setObject(X_, Y_, '.');
                X_ += 1;
                gameboard.setObject(X_, Y_, 'A');
                cout<<endl;
                system("pause");
                system("cls");
                gameboard.displayGameBoard();
                AlienTurn();
                display();
                zombie.display();
                cout<<endl;
                if (object == 'v' || object == '<' || object == '>' || object == '^')
            {
                change_direction(object, gameboard,zombie);
                break;
            }
            }
            
        }
        else if (X_ == gameboard.getDimX())
        {
            cout<<"Alien hits the border"<<endl;
            break;
        }
        else
        {
            break;
        }
    }
}

void Alien::A_up(GameBoard &gameboard,Zombie &zombie)
{
    bool movement = true;
    while (movement)
    {
        if (Y_ < gameboard.getDimY())
        {
            char object = gameboard.getObject(X_, Y_ + 1);
            next_object(movement, object,zombie,gameboard,X_, Y_ + 1);
            if (movement)
            {
                gameboard.setObject(X_, Y_, '.');
                Y_ += 1;
                gameboard.setObject(X_, Y_, 'A');
                cout<<endl;
                system("pause");
                system("cls");
                gameboard.displayGameBoard();
                AlienTurn();
                display();
                zombie.display();
                cout<<endl;
                if (object == 'v' || object == '<' || object == '>' || object == '^')
            {
                change_direction(object, gameboard,zombie);
                break;
            }
            }
            
        }
        else if (Y_ == gameboard.getDimY())
        {
            cout<<"Alien hits the border"<<endl;
            break;
        }
        else
        {
            break;
        }
    }
}

void Alien::A_down(GameBoard &gameboard,Zombie &zombie)
{
    bool movement = true;
    while (movement)
    {
        if (Y_ > 1)
        {
            char object = gameboard.getObject(X_, Y_ - 1);
            next_object(movement, object,zombie,gameboard,X_, Y_ - 1);
            if (movement)
            {
                gameboard.setObject(X_, Y_, '.');
                Y_ -= 1;
                gameboard.setObject(X_, Y_, 'A');
                cout<<endl;
                system("pause");
                system("cls");
                gameboard.displayGameBoard();
                AlienTurn();
                display();
                zombie.display();
                cout<<endl;
                if (object == 'v' || object == '<' || object == '>' || object == '^')
                {
                    change_direction(object, gameboard,zombie);
                    break;
                }
            }
        }
        else if (Y_ == 1)
        {
            cout<<"Alien hits the border"<<endl;
            break;
        }
        else
        {
            break;
        }
    }
}

void Alien::next_object(bool &movement, char object,Zombie &zombie,GameBoard &gameboard,int x,int y) // x,y is the object position
{
    if (object == ' ')
    {
        cout<<endl<<"Alien finds an empty space"<<endl;
    }
    else if (object == 'p')
    {
        GameObject::Pod_(zombie,gameboard,x,y); 
        zombie.zombieDied(gameboard); // zombie position become empty when pod kill the zombie
    }
    else if (object == 'h')
    {
        GameObject::Health_();
        change_life('+', 20);
    }
    else if (object == 'r')
    {
        movement = false;
        GameObject::Rock_(gameboard,x,y);
    }
    else if (object == '<')
    {
        cout<<"Alien finds an arrow."<<endl
        <<"Alien's attack is increase by 20"<<endl;
        change_attack('+',20);
    }
    else if (object == '>')
    {
        cout<<"Alien finds an arrow."<<endl
        <<"Alien's attack is increase by 20"<<endl;
        change_attack('+',20);
    }
    else if (object == '^')
    {
        cout<<"Alien finds an arrow."<<endl
        <<"Alien's attack is increase by 20"<<endl;
        change_attack('+',20);
    }
    else if (object == 'v')
    {
        cout<<"Alien finds an arrow."<<endl
        <<"Alien's attack is increase by 20"<<endl;
        change_attack('+',20);
    }
    else if (object == '.')
    {
    }
    else if (object == '1' || object == '2' || object == '3' || object == '4' || object == '5' || object == '6' || object == '7' || object == '8' || object == '9')
    {
        int zombie_sequence = object-48;
        movement = GameObject::Zombie_(zombie,zombie_sequence,AlienAttack_);
    }
    else{}
}

void Alien::change_direction(char object, GameBoard &gameboard,Zombie &zombie)
{
    if (object == '^')
    {
        A_up(gameboard,zombie);
    }
    else if (object == 'v')
    {
        A_down(gameboard,zombie);
    }
    else if (object == '<')
    {
        A_left(gameboard,zombie);
    }
    else if (object == '>')
    {
        A_right(gameboard,zombie);
    }
}

bool Alien::AlienLose()
{
    if (AlienLife_==0)
    {
        system("cls");
        cout<<endl<<"Alien died"<<endl
            <<"Game Over! Alien were defeated by the zombies, and the humans are in despair."<<endl;
        return false;
    }
    else
    {
        return true;
    }
}

void Alien::AlienTurn()
{
    cout<<"   Turn: Alien " <<endl;
}