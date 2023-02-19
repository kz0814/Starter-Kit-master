//SettingChange change to accept odd number only 
//Main_GameSetting cannot work normal if user input more than one character cause variable is char

// GameSetting.cpp
#include <iostream>
#include "GameSetting.hpp"
#include <string>
#include <limits>
using namespace std;

GameSetting::GameSetting()
    
{     dimX_=9;
      dimY_=5;
      ZombieNumber_=1;
}


void GameSetting::displayDefault() const // display default row and columns
{
    cout << "Default Game Settings" << endl
         << "-------------------------" << endl
         << "Board Rows     : " << getDimY() << endl
         << "Board Columns  : " << getDimX() << endl
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
    while (run_columns)
    {
    cout<< "Enter rows(odd number) => ";
    cin >> y;
    if (y%2 == 1 && y>0) //get only odd number 
    {
        run_columns=false;
    }
    else if(!cin)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
    }
    }
    

    while (run_rows) 
    {
    cout << "Enter columns(odd number) => ";
    cin >> x;
    if ( x%2 == 1 && x>0)  //get only odd number
    {
        run_rows=false; 
    }
    else if(!cin)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
    }
    }
    
    cout << endl
         << "Zombie Settings" << endl
         << "-----------------" << endl;
    while(run_nzombie)
    {
    cout<< "Enter number of zombies(min=1,max=9) => ";
    cin >> nzombie;
    if(nzombie < 10 && nzombie > 0) //get only number smaller than 10
    {
        run_nzombie=false;
    }
    else if(!cin)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
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
        cin>>ChangeSettings;
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
