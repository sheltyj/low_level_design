#include "header.h"

Grid ::Grid()
{
    cout << "Enter size of the grid" << endl;
    cin >> gridSize;
    vector<char> v(gridSize, '-');
    for (int i = 0; i < gridSize; i++)
    {
        grid.push_back(v);
    }
    gameClosed = false;
}

bool Grid ::isFull()
{
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            if (grid[i][j] == '-')
                return false;
        }
    }
    return true;
}

void Grid ::showGrid()
{
    for (int i = 0; i < gridSize; i++)
    {

        for (int j = 0; j < gridSize; j++)
        {
            cout << grid[i][j] << "  ";
        }
        cout << endl
             << endl;
    }
}
bool Grid ::fill(Player *currPlayer, int i, int j)
{
    i--;
    j--;
    if (i < 0 || i >= gridSize || j < 0 || j >= gridSize)
    {
        cout << "Invalid Entry... Please try again" << endl;
        return false;
    }
    if (grid[i][j] != '-')
    {
        cout << "this cell is already filled... please choose different" << endl;
        return false;
    }
    char piece = currPlayer->getPiece();
    grid[i][j] = piece;
    cout << "Successfully inserted into grid" << endl;
    if (isWin(i, j))
    {
        cout << currPlayer->getName() << " have won the game" << endl;
        showGrid();
        gameClosed = true;
    }
    return true;
}

bool Grid ::isWin(int i, int j)
{
    char piece = grid[i][j];
    bool ans = false;
    bool flag = true;
    for (int k = 0; k < gridSize; k++)
    {
        if (grid[i][k] != piece)
        {
            flag = false;
            break;
        }
    }
    if (flag)
        return true;
    flag = true;

    for (int k = 0; k < gridSize; k++)
    {
        if (grid[k][j] != piece)
        {
            flag = false;
            break;
        }
    }
    if (flag)
        return true;
    flag = true;
    for (int k = 0; k < gridSize; k++)
    {
        if (grid[k][k] != piece)
        {
            flag = false;
            break;
        }
    }
    int x = gridSize - 1;
    int y = 0;
    if (flag)
        return true;
    flag = true;
    for (int k = 0; k < gridSize; k++)
    {
        if (grid[x][y] != piece)
        {
            flag = false;
            break;
        }
        x--;
        y++;
    }
    return flag;
}

bool Grid ::isGameClosed()
{
    return gameClosed;
}
