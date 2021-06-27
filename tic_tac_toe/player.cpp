#include "header.h"


Player :: Player(int id)
{   
    cout<<"Get input for player"<<id+1<<endl;
    cout<<"Enter name of the player"<<endl;
    cin>>name;
    cout<<"Enter Piece of the Player"<<endl;
    cin>>piece;
    this->id=id;
}
string Player ::  getName()
{
    return name;
}
char Player :: getPiece()
{
    return piece;
}

