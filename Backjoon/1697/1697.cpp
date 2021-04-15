#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void makeTree(vector<vector<int> > &map, int row, int height)
{
    if (row < height)
    {
        for (int i = 0; i < map[row].size(); ++i)
        {
            map[row + 1].push_back(map[row][i] - 1);
            map[row + 1].push_back(map[row][i] + 1);
            map[row + 1].push_back(map[row][i] * 2);
        }
        makeTree(map, row + 1, height);
    }
}

void BFS(int start, vector<int> graph[], bool check[])
{
    queue<int> q;

    q.push(start);
    check[start] = true;

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        cout << tmp;
        for (int i = 0; i < graph[tmp].size(); ++i)
        {
            if (check[graph[tmp][i]] == false)
            {
                q.push(graph[tmp][i]);
                check[graph[tmp][i]] = true;
            }
        }
    }
}

int BFS(vector<vector<int> > map, int find)
{
    bool isFound = false;
    int height = 1;
    while (!isFound)
    {
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

    //cin >> subin >> sister;

    int q = (sister - subin) / subin;
    int r = (sister - subin) % subin;

    int h = q + r + 1;

    vector<vector<int> > map(h, vector<int>());
    map[0].push_back(subin);
    makeTree(map, 0, h - 1);

    // vector<bool> check(map[h - 1].back());

    //cout << BFS(map, sister) << endl;
    for (int i = 0; i < map.size(); ++i)
    {
        for (int j = 0; j < map[i].size(); ++j)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}