//GameSetting.hpp
#ifndef GAMESETTING_H
#define GAMESETTING_H



class GameSetting
{

public:
    //value
    int dimX_,dimY_; // to indicate private data
    int ZombieNumber_;
    GameSetting();//default value 
    //return value
    int getDimX() const
    {
        return dimX_;
    };
    int getDimY() const
    {
        return dimY_;
    }
    int getZombieNumber() const
    {
        return ZombieNumber_;
    }

    //function
    void displayDefault() const; //display the default row,columns and zombie number
    void SettingChange()  ; //change the default ro,columns and zombie number
    void Main_GameSetting();//combie all function
};

#endif



