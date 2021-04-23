#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, u, v;

vector<vector<int>> map;
vector<bool> visited;

void DFS(int start, int &count)
{
    if (!visited[start])
    {
        visited[start] = true;
        count += 1;

        for (int i = 0; i < map[start].size(); ++i)
        {
            DFS(map[start][i], count);
        }
    }
}

int main()
{
    cin >> N >> M;

    // resize
    map.resize(N + 1);
    visited.resize(N + 1);

    fill(visited.begin(), visited.end(), false);

    for (int i = 0; i < M; ++i)
    {
        cin >> u >> v;

        auto isInU = find(map[u].begin(), map[u].end(), v);
        auto isInV = find(map[v].begin(), map[v].end(), u);

        if (isInU == map[u].end())
        {
            map[u].push_back(v);
        }

        if (isInV == map[v].end())
        {
            map[v].push_back(u);
        }
    }

    int cnt = 0;
    int answer = 1;
    // DFS
    DFS(1, cnt);
    while (cnt < N)
    {
        int flag = -1;
        for (int i = 1; i < visited.size(); ++i)
        {
            if (!visited[i])
            {
                flag = i;
                break;
            }
        }
        answer++;
        DFS(flag, cnt);
    }
    cout << answer << endl;

    return 0;
}