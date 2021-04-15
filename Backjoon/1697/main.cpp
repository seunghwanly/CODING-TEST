#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void makeTree(vector<vector<int> > &map, int row)
{
    if (row < map.size())
    {
        for (int i = 0; i < map[row - 1].size(); ++i)
        {
            map[row].push_back(map[row - 1][i] - 1);
            map[row].push_back(map[row - 1][i] + 1);
            map[row].push_back(map[row - 1][i] * 2);
        }
        makeTree(map, row + 1);
    }
}

int BFS(vector<vector<int> > map, int find)
{
    if (map.size() == 1 && map[0][0] == find)
        return 0;
    bool isFound = false;
    int height = 1;
    while (!isFound)
    {
        if (height > map.size())
            return -1;
        for (int i = 0; i < map[height].size(); ++i)
        {
            if (map[height][i] == find)
            {
                isFound = true;
                break;
            }
        }
        height++;
    }
    return height - 1;
}

int main()
{

    int subin = 5;
    int sister = 17;

    cin >> subin >> sister;

    int gap = abs(sister - subin);
    int h = subin != 0 ? int(gap / subin) + gap % subin + 1 : int(gap / 2);

    vector<vector<int> > map(h, vector<int>());
    map[0].push_back(subin);

    makeTree(map, 1);

    cout << BFS(map, sister);

    return 0;
}