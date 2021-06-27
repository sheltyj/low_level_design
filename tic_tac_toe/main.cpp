
#include "header.h"


int main()
{
    General *generalObject = new General();
    Grid *gridObject = new Grid();
    int turn=0;
    while(turn!=-1)
    {
        Player *currPlayer =  generalObject->getPlayer(turn);
        gridObject->showGrid();
        cout<<"Enter cell position to be inserted for " << currPlayer->getName()<<endl;
        int i,j;
        cin>>i>>j;
        bool isPossible = gridObject->fill(currPlayer, i, j);
        if(isPossible)
        {
            turn++;
            turn = turn%generalObject->getCountPlayers();
        }
        if(gridObject->isFull())
        {
            cout<<"match closed at drawn"<<endl;
            turn =-1;
        }
        if(gridObject->isGameClosed()) turn=-1;
    }


}