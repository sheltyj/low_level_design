#include "header.h"

General ::General()
{
    cout << "Enter total number of players" << endl;
    cin >> countPlayers;
    for (int i = 0; i < countPlayers; i++)
    {
        Player *p = new Player(i);
        allPlayers.push_back(p);
    }
}
int General ::getCountPlayers()
{
    return countPlayers;
}

Player* General ::getPlayer(int i)
{
    return allPlayers[i];
}
