#include <iostream>
#include <vector>
#include "Character.hpp"
#include "GameBoard.hpp"
#include "GameObject.hpp"
using namespace std;

void GameObject::Health_()
{
    cout << "Alien finds a health pack." << endl
         << "Alien's life is increased by 20." << endl;
}

void GameObject::Pod_(Zombie &zombie, GameBoard &gameboard, int x, int y) // x,y is position of object p finded
{
    cout << "Alien finds a pod." << endl;
    char i;
    bool find = false;
    // find nearest i in same columm and row with p object
    for (int j = 1; j < gameboard.getDimX() + gameboard.getDimY(); ++j)
    {
        if (x - j > 0)
        {
            i = gameboard.getObject(x - j, y);
            if (i == '1' || i == '2' || i == '3' || i == '4' || i == '5' || i == '6' || i == '7' || i == '8' || i == '9')

            {

                find = true;
                break;
            }
            else
            {
            }
        }
        if (y + j < gameboard.getDimY() + 1)
        {
            i = gameboard.getObject(x, y + j);
            if (i == '1' || i == '2' || i == '3' || i == '4' || i == '5' || i == '6' || i == '7' || i == '8' || i == '9')
            {

                find = true;
                break;
            }
            else
            {
            }
        }
        if (x + j < gameboard.getDimX() + 1)
        {
            i = gameboard.getObject(x + j, y);
            if (i == '1' || i == '2' || i == '3' || i == '4' || i == '5' || i == '6' || i == '7' || i == '8' || i == '9')

            {
                find = true;
                break;
            }
            else
            {
            }
        }
        if (y - j > 0)
        {
            i = gameboard.getObject(x, y - j);
            if (i == '1' || i == '2' || i == '3' || i == '4' || i == '5' || i == '6' || i == '7' || i == '8' || i == '9')
            {
                find = true;
                break;
            }
            else
            {
            }
        }
    }
    // if i finded
    if (find)
    {
        int damage = 10;

        int a = i - 48;
        zombie.change_life(a, '-', damage);
        cout << "Zombie " << i << " receives a damages of " << damage << endl;
        if (zombie.GetZombieLife(a) > 0)
        {
            cout << "Zombie " << i << " still alive" << endl;
        }
        else
        {
            cout << "Zombie " << i << " died" << endl;
        }
    }
    else
    {
        cout << "no zombie nearby" << endl;
    }
}

void GameObject::Rock_(GameBoard &gameboard, int x, int y)
{
    cout << "Alien stumbles upon a rock." << endl;
    char objects[] = {'h', 'p', '^', '<', '>', 'v', ' '};
    int noOfObjects = 7; // number of object in the array
    char new_objects = objects[rand() % noOfObjects]; 

    //determine new object
    if(new_objects=='h')
    {
        cout<< "Alien discovers a health_pack beneath the rock."<<endl;
    }
    else if(new_objects == 'p')
    {
        cout<< "Alien discovers a pod beneath the rock."<<endl;
    }
    else if(new_objects == '^'||'<'||'>'||'v')
    {
        cout<< "Alien discovers an arrow beneath the rock."<<endl;
    }
    else if(new_objects == ' ')
    {
        cout<< "Alien discovers an empty rock."<<endl;
    }
    else{}

    gameboard.setObject(x,y,new_objects);

}

bool GameObject::Zombie_(Zombie& zombie,int sequence,int alien_attack)
{
    cout<<"Alien attacks Zombie "<< sequence <<"."<<endl;
    cout<<"Zombie "<< sequence << " receives a damages of "<< alien_attack<< "."<<endl;
    zombie.change_life(sequence,'-',alien_attack); //minus zombie life by alien attack
    //zombie alive or died
    if (zombie.GetZombieLife(sequence) > 0) //zombie alive
    {
        cout<<"Zombie "<< sequence << " is still alive."<<endl;
        return false;
    }
    else  //zombie died
    {
        cout <<"Zombie "<< sequence <<" is defeated."<<endl;
        return true;
    }
}
