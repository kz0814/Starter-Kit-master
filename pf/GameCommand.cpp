#include "GameCommand.hpp"
#include "GameBoard.hpp"
#include "GameSetting.hpp"
#include "Character.hpp"
#include <iostream>
#include <fstream>
#include <iterator>
#include <limits>
#include <sstream> //use stringstream

using namespace std;

void COMMAND::help()
{
    cout << endl
         << endl
         << "Command" << endl
         << "1. up     - Move up." << endl
         << "2. down   - Move down." << endl
         << "3. left   - Move left." << endl
         << "4. right  - Move right." << endl
         << "5. arrow  - Change the direction of an arrow." << endl
         << "6. help   - Display these user commands." << endl
         << "7. save   - Save the game." << endl
         << "8. load   - Load the game." << endl
         << "9. quit   - Quit the game." << endl;
}

void COMMAND::arrow(GameBoard &gameboard)
{
    int row, column; // row=y ,column=x
    string direction;
    bool change_arrow = true;
    while (change_arrow)
    {
        cout << "Enter row, column, and direction: ";
        cin >> row;
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            change_arrow = false;
            cout << "Pls enter number for row" << endl;
            break;
        }
        cin >> column;
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            change_arrow = false;
            cout << "Pls enter number for column" << endl;
            break;
        }
        cin >> direction;

        char ori_arrow = gameboard.getObject(column, row);
        if (ori_arrow == '^' || ori_arrow == '<' || ori_arrow == '>' || ori_arrow == 'v')
        {
            // create new_arrow direction
            char new_arrow;
            if (direction == "up")
            {
                new_arrow = '^';
                // ori_arrow change to new arrow
                gameboard.setObject(column, row, new_arrow);
                cout << "Arrow " << ori_arrow << " is switched to " << new_arrow << "." << endl;
            }
            else if (direction == "down")
            {
                new_arrow = 'v';
                // ori_arrow change to new arrow
                gameboard.setObject(column, row, new_arrow);
                cout << "Arrow " << ori_arrow << " is switched to " << new_arrow << "." << endl;
            }
            else if (direction == "left")
            {
                new_arrow = '<';
                // ori_arrow change to new arrow
                gameboard.setObject(column, row, new_arrow);
                cout << "Arrow " << ori_arrow << " is switched to " << new_arrow << "." << endl;
            }
            else if (direction == "right")
            {
                new_arrow = '>';
                // ori_arrow change to new arrow
                gameboard.setObject(column, row, new_arrow);
                cout << "Arrow " << ori_arrow << " is switched to " << new_arrow << "." << endl;
            }
            else
            {
                cout << "Pls enter left/right/up/down for direction." << endl;
            }
        }
        else
        {
            cout << "Cannot find any arrow in this position." << endl;
        }
        change_arrow = false;
    }
}

void COMMAND::save(GameSetting &gamesetting, GameBoard &gameboard, Zombie &zombie, Alien &alien)
{
    string filename;
    cout << "Enter the file name to save the current game(.txt): ";
    cin.ignore();
    getline(cin, filename);
    ofstream MyFile(filename);
    // gamesetting
    MyFile << gamesetting.dimX_ << endl;
    MyFile << gamesetting.dimY_ << endl;
    MyFile << gamesetting.ZombieNumber_ << endl;

    // gameboard
    MyFile << gameboard.getDimX() << endl;
    MyFile << gameboard.getDimY() << endl;

    // alien
    MyFile << alien.GetAlienLife() << endl;
    MyFile << alien.GetAlienAttack() << endl;
    MyFile << alien.GetAlienX() << endl;
    MyFile << alien.GetAlienY() << endl;

    // zombie
    MyFile << zombie.dimX_ << endl;
    MyFile << zombie.dimY_ << endl;
    MyFile << zombie.ZombieNumber_ << endl;
    ostream_iterator<int> output_life(MyFile, " ");
    std::copy(zombie.Life_.begin(), zombie.Life_.end(), output_life);
    MyFile << endl;
    ostream_iterator<int> output_attack(MyFile, " ");
    std::copy(zombie.Attack_.begin(), zombie.Attack_.end(), output_attack);
    MyFile << endl;
    ostream_iterator<int> output_range(MyFile, " ");
    std::copy(zombie.Range_.begin(), zombie.Range_.end(), output_range);
    MyFile << endl;
    ostream_iterator<int> output_x(MyFile, " ");
    std::copy(zombie.X_.begin(), zombie.X_.end(), output_x);
    MyFile << endl;
    ostream_iterator<int> output_y(MyFile, " ");
    std::copy(zombie.Y_.begin(), zombie.Y_.end(), output_y);
    MyFile << endl;

    // gamesetting
    for (int i = 0; i < gamesetting.dimY_; ++i)
    {
        for (int j = 0; j < gamesetting.dimX_; ++j)
        {
            MyFile << gameboard.map_[i][j];
        }
        MyFile << endl;
    }

    MyFile.close();

    cout << "Game Saved" << endl;
}

void COMMAND::load(GameSetting &gamesetting, GameBoard &gameboard, Zombie &zombie, Alien &alien)
{
    string Save;
    bool savegame = true;
    while (savegame)
    {
        cout << "Do you want to save the current game?(y/n) : ";
        cin >> Save;
        if (Save == "y")
        {
            save(gamesetting, gameboard, zombie, alien);
            savegame = false;
        }
        else if (Save == "n")
        {
            savegame = false;
        }
    }
    string filename;
    cout << "Enter the file name to load: ";
    cin >> filename;
    ifstream MyFile(filename);
    if (MyFile)
    {
        MyFile >> gamesetting.dimX_;
        MyFile >> gamesetting.dimY_;
        MyFile >> gamesetting.ZombieNumber_;
        MyFile >> gameboard.dimX_;
        MyFile >> gameboard.dimY_;
        MyFile >> alien.AlienLife_;
        MyFile >> alien.AlienAttack_;
        MyFile >> alien.X_;
        MyFile >> alien.Y_;
        MyFile >> zombie.dimX_;
        MyFile >> zombie.dimY_;
        MyFile >> zombie.ZombieNumber_;
        string jump;
        getline(MyFile, jump);
        string Life;
        string Attack;
        string Range;
        string X;
        string Y;
        getline(MyFile, Life);
        getline(MyFile, Attack);
        getline(MyFile, Range);
        getline(MyFile, X);
        getline(MyFile, Y);
        split(Life, zombie.Life_);
        split(Attack, zombie.Attack_);
        split(Range, zombie.Range_);
        split(X, zombie.X_);
        split(Y, zombie.Y_);

        // for the gameboard 2D map
        //  create dynamic 2D array using vector
        gameboard.map_.resize(gameboard.dimY_); // create empty rows
        for (int i = 0; i < gameboard.dimY_; ++i)
        {
            gameboard.map_[i].resize(gameboard.dimX_); // resize each row
        }
        for (int i = 0; i < gamesetting.dimY_; ++i)
        {
            string object;
            getline(MyFile, object);
            for (int j = 0; j < gamesetting.dimX_; ++j)
            {
                gameboard.map_[i][j] = object[j]; // input the object back to each row
            }
        }
        MyFile.close(); // if the file does not exist
    }
    else
    {
        cout << "The file name:" << filename << " does not exist" << endl;
    }
}

void COMMAND::quit_game()
{
    string Quit;
    bool answer = true;
    while (answer)
    {
        cout << "Are you sure (y/n):";
        cin >> Quit;
        if (Quit == "y")
        {
            cout << endl
                 << "Goodbye!" << endl;
            system("pause");
            exit(0);
        }
        else if (Quit == "n")
        {
            cout << endl
                 << "Enjoy your game" << endl;
            answer = false;
        }
        else
        {
        }
    }
}

// Function to split the string to int in vector
void COMMAND::split(string &String, vector<int> &Vector)
{
    Vector.clear();                // clear the old one vector
    std::istringstream is(String); // split the spring
    int n;
    while (is >> n)
    {
        Vector.push_back(n); // insert the string value to vector
    }
}