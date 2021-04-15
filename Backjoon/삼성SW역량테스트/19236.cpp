#include <iostream>
#include <vector>

using namespace std;

struct Pos
{
    int x;
    int y;
};

struct Fish
{
    int name;
    int head;
    Pos pos;
};

Fish map[4][4] = {
    0,
};

bool isInside(Pos pos)
{
    if (pos.x < 0 || pos.x > 3)
        return false;
    if (pos.y < 0 || pos.y > 3)
        return false;
    return true;
}

Pos checkPosition(int head, Pos pos)
{
    Pos result;
    switch (head)
    {
    case 1:
        result.x = pos.x - 1;
        result.y = pos.y;
        break;
    case 2:
        result.x = pos.x - 1;
        result.y = pos.y - 1;
        break;
    case 3:
        result.x = pos.x;
        result.y = pos.y - 1;
        break;
    case 4:
        result.x = pos.x + 1;
        result.y = pos.y - 1;
        break;
    case 5:
        result.x = pos.x + 1;
        result.y = pos.y;
        break;
    case 6:
        result.x = pos.x + 1;
        result.y = pos.y + 1;
        break;
    case 7:
        result.x = pos.x;
        result.y = pos.y + 1;
        break;
    case 8:
        result.x = pos.x - 1;
        result.y = pos.y + 1;
        break;
    default:
        break;
    }
    return result;
}

bool isSafetoMove(Fish fish)
{
    // sharnk name is -1
    if (fish.name != -1)
    {
        Pos temp = checkPosition(fish.head, fish.pos);
        // is shark && out of range && other fish
        if ((map[temp.x][temp.y].name == -1) &&
            (temp.x < 0 || temp.x > 3 || temp.y < 0 || temp.y > 3) &&
            map[temp.x][temp.y].name != 0)
        {
            return false;
        }
        else
            return true;
    }
    return false;
}
// return if nothing -1
int getMaxFishSharktoEat(Fish fish)
{
    // only for Shark
    if (fish.name == -1)
    {
        vector<int> fishes = vector<int>();
        Pos temp = fish.pos;
        while (isInside(temp))
        {
            temp = checkPosition(fish.head, temp);
            fishes.push_back(map[temp.x][temp.y].name);
        }
        int max = -1;
        for (int i = 0; i < fishes.size(); ++i)
        {
            if (fishes[i] > max)
            {
                max = fishes[i];
            }
        }
    }
    return -1;
}

void turnHead(int &head)
{
    if (head < 8)
    {
        head++;
    }
    else
    {
        head = 1;
    }
}

void swapFish(Fish &x, Fish &y) {
    Fish temp = x;
    x = y;
    y = temp;
}

int main()
{

    int input = 0;

    // fish pos array
    Fish arrayFish[16] = {};

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            cin >> input;
            if (j % 2 == 0)
            {
                map[i][j / 2].name = input;
            }
            else
            {
                map[i][j / 2].head = input;
                map[i][j / 2].pos.x = i;
                map[i][j / 2].pos.y = int(j / 2);
                // push into array
                arrayFish[i*4 + int(j / 2)] = map[i][j / 2];
            }
        }
    }
    // process
    int sum = 0;
    int flag = 0;
    // init shark
    Fish shark;
    shark.name = -1;
    shark.head = map[0][0].head;
    shark.pos = map[0][0].pos;

    while (isInside(shark.pos))
    {
        // shark in first process
        if (sum == 0)
        {
            sum += map[0][0].name;
            arrayFish[map[0][0].name].name = 0;
            map[0][0].name = 0;
            flag++;
        }
        if (flag % 2 != 0)
        {
            // fishes move
            int count = 0;
            // x : count / 4, y : count - count / 4
            for(int i=0; i<16; ++i) {
                
            }
        }
    }

    // map
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << map[i][j].name << " ";
        }
        cout << endl;
    }

    return 0;
}