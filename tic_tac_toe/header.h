#include<bits/stdc++.h>
using namespace std;


class Player
{
    int id; 
    string name; 
    char piece;
    

    public:

    Player(int id);
    string getName();
    char getPiece();
};



class General
{
    vector<Player*> allPlayers;
    int countPlayers;
    
    public :
    General();
    int getCountPlayers();
    Player* getPlayer(int i);
};



class Grid
{
    int gridSize;
    vector<vector<char> > grid;
    bool gameClosed=false;
    
    public:
    Grid(); 
    void showGrid();
    bool isFull();
    bool fill(Player *currPlayer, int i, int j);
    bool isWin(int i, int j);
    bool isGameClosed();
};