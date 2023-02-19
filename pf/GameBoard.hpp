#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <vector>
#include "GameSetting.hpp"
using namespace std;

class GameBoard
{
private:
    vector<vector<char>> map_;
    int dimX_, dimY_;
public:
    GameBoard()
    {};
    void setvalue(GameSetting &setting)//set value depend on user input from Gamesetting 
    {
        dimX_ = setting.dimX_;
        dimY_ = setting.dimY_;
    };

    void init(GameSetting &setting);
    void displayGameBoard() const;

    int getDimX()
    {
        return dimX_;
    };
    int getDimY() 
    {
        return dimY_ ;
    };
    char getObject(int x, int y)
    {
        return map_[dimY_-y][x-1];
    };
    void setObject(int x, int y, char object)
    {
        map_[dimY_-y][x-1]=object;
    };
};

#endif
