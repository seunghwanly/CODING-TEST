#include <iostream>
#include <string>

using namespace std;

const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

const char board[5][5] = {
    {'U', 'R', 'L', 'P', 'M'},
    {'X', 'P', 'R', 'E', 'T'},
    {'G', 'I', 'A', 'E', 'T'},
    {'X', 'T', 'N', 'Z', 'Y'},
    {'X', 'O', 'Q', 'R', 'S'}};

bool inRange(int y, int x)
{
    if (x < 0 && x > 4)
        return false;
    if (y < 0 && y > 4)
        return false;
    return true;
}

bool hasWord(int y, int x, const string &word)
{
    if (!inRange(y, x))
    {
        return false;
    }
    if (board[y][x] != word[0])
    {
        return false;
    }
    if (word.size() == 1)
    {
        return true;
    }
    for (int dir = 0; dir < 8; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];
        if (hasWord(nextY, nextX, word.substr(1)))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string find = "PRETTY";
    bool isFound, exitOuterLoop = false;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (hasWord(i, j, find))
            {
                isFound = true;
            }
            if (isFound)
            {
                exitOuterLoop = true;
                break;
            }
        }
        if (!exitOuterLoop)
            break;
    }

    cout << isFound << endl;

    return 0;
}