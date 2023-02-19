#include <iostream>
#include <vector>
#include <windows.h> //for beep sound
#include "Character.hpp"
#include "GameBoard.hpp"
#include "ZombieMoveAttack.hpp"
using namespace std;

bool ZombieMovement::Zombie_up(GameBoard &gameboard, Zombie &zombie, int sequence)
{
    int x = zombie.GetZombieX(sequence);
    int y = zombie.GetZombieY(sequence);
    if (y + 1 <= gameboard.getDimY())
    {
        char nextObject = gameboard.getObject(x, y + 1); // check upward
        if (nextObject == 'A' || nextObject == '1' || nextObject == '2' || nextObject == '3' || nextObject == '4' || nextObject == '5' || nextObject == '6' || nextObject == '7' || nextObject == '8' || nextObject == '9')
        {
            return true;
        }
        else
        {
            gameboard.setObject(x, y + 1, sequence + 48);
            gameboard.setObject(x, y, ' ');
            zombie.Y_[sequence] = y + 1;
            cout << "Zombie " << sequence << " moves up." << endl;

            return false;
        }
    }
    else
    {
        return true;
    }
}

bool ZombieMovement::Zombie_down(GameBoard &gameboard, Zombie &zombie, int sequence)
{

    int x = zombie.GetZombieX(sequence);
    int y = zombie.GetZombieY(sequence);
    if (y - 1 > 0)
    {
        char nextObject = gameboard.getObject(x, y - 1); // check downward
        if (nextObject == 'A' || nextObject == '1' || nextObject == '2' || nextObject == '3' || nextObject == '4' || nextObject == '5' || nextObject == '6' || nextObject == '7' || nextObject == '8' || nextObject == '9')
        {
            return true;
        }
        else
        {
            gameboard.setObject(x, y - 1, sequence + 48);
            gameboard.setObject(x, y, ' ');
            zombie.Y_[sequence] = y - 1;
            cout << "Zombie " << sequence << " moves down." << endl;

            return false;
        }
    }
    else
    {
        return true;
    }
}

bool ZombieMovement::Zombie_left(GameBoard &gameboard, Zombie &zombie, int sequence)
{
    int x = zombie.GetZombieX(sequence);
    int y = zombie.GetZombieY(sequence);
    char nextObject = gameboard.getObject(x - 1, y); // check to the left
    if (nextObject == 'A' || nextObject == '1' || nextObject == '2' || nextObject == '3' || nextObject == '4' || nextObject == '5' || nextObject == '6' || nextObject == '7' || nextObject == '8' || nextObject == '9' || x - 1 <= 0)
    {
        return true;
    }
    else
    {
        gameboard.setObject(x - 1, y, sequence + 48);
        gameboard.setObject(x, y, ' ');
        zombie.X_[sequence] = x - 1;
        cout << "Zombie " << sequence << " moves left." << endl;

        return false;
    }
}

bool ZombieMovement::Zombie_right(GameBoard &gameboard, Zombie &zombie, int sequence)
{
    int x = zombie.GetZombieX(sequence);
    int y = zombie.GetZombieY(sequence);
    char nextObject = gameboard.getObject(x + 1, y); // check to the right
    if (nextObject == 'A' || nextObject == '1' || nextObject == '2' || nextObject == '3' || nextObject == '4' || nextObject == '5' || nextObject == '6' || nextObject == '7' || nextObject == '8' || nextObject == '9' || x + 1 > gameboard.getDimX())
    {
        return true;
    }
    else
    {
        gameboard.setObject(x + 1, y, sequence + 48);
        gameboard.setObject(x, y, ' ');
        zombie.X_[sequence] = x + 1;
        cout << "Zombie " << sequence << " moves right." << endl;

        return false;
    }
}

void ZombieMovement::Zombie_move(GameBoard &gameboard, Zombie &zombie, int sequence)
{
    bool Zom_Move = true;
    while (Zom_Move)
    {
        int rand_num = rand() % 5; // 5 possibilities
        if (rand_num == 0)
        {
            // cout << "up" << endl;
            Zom_Move = Zombie_up(gameboard, zombie, sequence);
        }
        if (rand_num == 1)
        {
            // /cout << "move down" << endl;
            Zom_Move = Zombie_down(gameboard, zombie, sequence);
        }
        else if (rand_num == 2)
        {
            // cout << "move left" << endl;
            Zom_Move = Zombie_left(gameboard, zombie, sequence);
        }
        else if (rand_num == 3)
        {
            // cout << "right" << endl;
            Zom_Move = Zombie_right(gameboard, zombie, sequence);
        }
        else if (rand_num == 4)
        {
            cout << "Zombie " << sequence << " doesn't move" << endl;
            Zom_Move = false;
        }
    }
}

void ZombieMovement::Zombie_sound_attack()
{
    int attack;
    attack = rand() % 4;
    if (attack == 0)
    {
        cout << "Zombie attack the Walkie dokie!! Noisy sound appears." << endl;
        Beep(500, 2000);
    }
    else
    {
    }
}

void ZombieMovement::Zombie_Found_Attack_Alien(GameBoard &gameboard, Zombie &zombie, Alien &alien, int sequence)
{
    char nextObject;
    // To find the nearest Alien in same column & also row
    int x = zombie.GetZombieX(sequence);
    int y = zombie.GetZombieY(sequence);
    cout << endl;
    for (int j = 1; j <= zombie.GetZombieRange(sequence); ++j)
    {
        if (x + j < gameboard.getDimX() + 1)
        {
            nextObject = gameboard.getObject(x + j, y);
            if (nextObject == 'A')
            {
                cout << "Zombie " << sequence << " attacks Alien." << endl
                     // get one of the Zombie's attack.
                     << "Alien receives a damage of " << zombie.Attack_[sequence - 1] << endl;
                // Possible damage that Alien would receive.
                alien.change_life('-', zombie.GetZombieAttack(sequence)); // received damage accor. to respective zombie
                break;
            }
        }
        if (x - j > 0)
        {
            nextObject = gameboard.getObject(x - j, y);
            if (nextObject == 'A')
            {
                cout << "Zombie " << sequence << " attacks Alien." << endl
                     // get one of the Zombie's attack.
                     << "Alien receives a damage of " << zombie.Attack_[sequence - 1] << endl;
                // Possible damage that Alien would receive.
                alien.change_life('-', zombie.GetZombieAttack(sequence)); // received damage accor. to respective zombie
                break;
            }
        }
        if (y - j > 0)
        {
            nextObject = gameboard.getObject(x, y - j);
            if (nextObject == 'A')
            {
                cout << "Zombie " << sequence << " attacks Alien." << endl
                     // get one of the Zombie's attack.
                     << "Alien receives a damage of " << zombie.Attack_[sequence - 1] << endl;
                // Possible damage that Alien would receive.
                alien.change_life('-', zombie.GetZombieAttack(sequence)); // received damage accor. to respective zombie
                break;
            }
        }
        if (y + j < gameboard.getDimY() + 1)
        {
            nextObject = gameboard.getObject(x, y + j);
            if (nextObject == 'A')
            {
                cout << "Zombie " << sequence << " attacks Alien." << endl
                     // get one of the Zombie's attack.
                     << "Alien receives a damage of " << zombie.Attack_[sequence - 1] << endl;
                // Possible damage that Alien would receive.
                alien.change_life('-', zombie.GetZombieAttack(sequence)); // received damage accor. to respective zombie
                break;
            }
        }
    }
    if (nextObject != 'A')
    {
        cout << "Zombie " << sequence << " is unable to attack Alien." << endl
             << "Alien is too far." << endl;
    }
    Zombie_sound_attack();
    system("pause");
    system("cls");
    gameboard.displayGameBoard();
    zombie.ZombieTurn(sequence);
    alien.display();
    zombie.display();
    cout << endl
         << "Zombie " << sequence << "'s turn ends." << endl;
}
