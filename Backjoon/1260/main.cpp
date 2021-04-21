#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int>> map;

vector<int> pathDFS;
vector<int> pathBFS;

bool visitedDFS[1000];
bool visitedBFS[1000];

// root = 1
void DFS(int start)
{
    visitedDFS[start] = true;

    // insert into path
    pathDFS.push_back(start);

    for (int i = 0; i < map[start].size(); ++i)
    {
        if (!visitedDFS[map[start][i]])
        {
            DFS(map[start][i]);
        }
    }
}

void BFS(int start)
{
    // queue
    queue<int> q;
    // queue init
    visitedBFS[start] = true;
    pathBFS.push_back(start);
    q.push(start);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (int i = 0; i < map[front].size(); ++i)
        {
            if (!visitedBFS[map[front][i]])
            {
                q.push(map[front][i]);
                visitedBFS[map[front][i]] = true;
                pathBFS.push_back(map[front][i]);
            }
        }
    }
}

int main()
{
    // visit init
    for (auto item : visitedDFS)
    {
        item = false;
    }
    for (auto item : visitedBFS)
    {
        item = false;
    }

    cin >> N >> M >> V;
    map.resize(N + 1);

    for (int i = 0; i < M; ++i)
    {
        int start, arrive;
        cin >> start >> arrive;
        bool isInStart = false;
        for (int j = 0; j < map[start].size(); ++j)
        {
            if (map[start][j] == arrive)
                isInStart = true;
        }
        if (!isInStart)
            map[start].push_back(arrive);
        bool isInArrive = false;
        for (int j = 0; j < map[arrive].size(); ++j)
        {
            if (map[arrive][j] == start)
                isInArrive = true;
        }
        if (!isInArrive)
            map[arrive].push_back(start);
    }

    // map sort
    for (int i = 0; i < map.size(); ++i)
    {
        if (map[i].size() > 1)
        {
            sort(map[i].begin(), map[i].end());
        }
    }

    DFS(V);
    BFS(V);

    // DFS
    // cout << "DFS : ";
    for (int i = 0; i < pathDFS.size(); ++i)
    {
        cout << pathDFS[i] << " ";
    }
    cout << endl;
    // BFS
    // cout << "BFS : ";
    for (int i = 0; i < pathBFS.size(); ++i)
    {
        cout << pathBFS[i] << " ";
    }
    cout << endl;

    return 0;
}