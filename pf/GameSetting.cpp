//SettingChange change to accept odd number only 
//Main_GameSetting cannot work normal if user input more than one character cause variable is char

// GameSetting.cpp
#include <iostream>
#include "GameSetting.hpp"
#include <string>
using namespace std;

GameSetting::GameSetting()
    
{     dimX_=5;
      dimY_=9;
      ZombieNumber_=1;
}


void GameSetting::displayDefault() const // display default row and columns
{
    cout << "Default Game Settings" << endl
         << "-------------------------" << endl
         << "Board Rows     : " << getDimX() << endl
         << "Board Columns  : " << getDimY() << endl
         << "Zombie Count   : " << getZombieNumber() << endl
         << endl;
}

void GameSetting::SettingChange() // change number of row,columns and nzombie
{
    system("cls"); //clean the terminal
    int x;int y;int nzombie;
    cout << "Board Settings" << endl
         << "------------------" << endl;
    bool run_rows=true;
    bool run_columns=true;
    bool run_nzombie=true;
    while (run_rows)
    {
    cout<< "Enter rows(odd number) => ";
    cin >> x;
    if ( x%2 == 1)  //get only odd number
    {
        run_rows=false; 
    }
    }

    while (run_columns) 
    {
    cout << "Enter columns(odd number) => ";
    cin >> y;
    if (y%2 == 1) //get only odd number
    {
        run_columns=false;
    }
    }
    cout << endl
         << "Zombie Settings" << endl
         << "-----------------" << endl;
    while(run_nzombie)
    {
    cout<< "Enter number of zombies(max zombie=9) => ";
    cin >> nzombie;
    if(nzombie < 10) //get only number smaller than 10
    {
        run_nzombie=false;
    }
    }
    cout << endl
         << "Settings Updated." << endl;
    dimX_ = x;
    dimY_ = y;
    ZombieNumber_ = nzombie;
}

void GameSetting::Main_GameSetting()
{
    displayDefault();
    string ChangeSettings;
    bool run = true;
    
    cout << "Do you wish to change the game settings (y/n) => ";

    while (run)
    {
        getline(cin,ChangeSettings);
        if (ChangeSettings == "y" || ChangeSettings =="Y")
        {
            SettingChange();
            run = false;

        }
        else if (ChangeSettings == "n" || ChangeSettings == "N")
        {
            run = false;
        }
        else
        {
            cout << "Pls enter (y/n) => "; //loop continue until get (y/n)
        }
        
    }
}
