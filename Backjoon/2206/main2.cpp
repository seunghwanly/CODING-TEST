#include <iostream>
#include <queue>
#include <string> // for input
#include <math.h> // for distance
#include <vector> // for path

using namespace std;

int N, M;                  // y , x
int dy[4] = {0, 1, 0, -1}; // right, down, left, top
int dx[4] = {1, 0, -1, 0};
// for map
int map[1000][1000] = {
    0,
};
bool visited[1000][1000] = {
    false,
};

bool canBreak = true; // for only one time

struct pos
{
    int y, x, passed;
    vector<int> path; // for path : 010000
};

bool inRange(pos p)
{
    return p.y >= 0 && p.y < N && p.x >= 0 && p.x < M;
}

bool isSurrounded(pos p)
{
    bool res = true;
    for (int i = 0; i < 4; ++i)
    {
        int ny = p.y + dy[i];
        int nx = p.x + dx[i];
        if (inRange({ny, nx}))
        {
            if (map[ny][nx] != 1)
                res = false;
        }
    }
    return res;
}

void DFSEdge(pos curr, vector<int> &path)
{
    if (curr.y == N - 1 && curr.x == M - 1)
        return;
    if (curr.y == N - 1)
    {
        // turn
        path.push_back(map[curr.y][curr.x]);
        DFSEdge({curr.y, curr.x + 1}, path);
    }
    if (curr.x == M - 1)
    {
        // turn
        path.push_back(map[curr.y][curr.x]);
        DFSEdge({curr.y + 1, curr.x}, path);
    }
    path.push_back(map[curr.y][curr.x]);
    DFSEdge({curr.y + 1, curr.x}, path);
    DFSEdge({curr.y, curr.x + 1}, path);
}

pos BFS(pos begin, pos end, bool ignore)
{
    // for return
    pos res;
    // for bfs
    queue<pos> q;
    begin.path.push_back(map[begin.y][begin.x]);
    begin.passed += 1;
    q.push(begin);
    visited[begin.y][begin.x] = true;

    // while loop
    while (!q.empty())
    {
        pos front = q.front();
        q.pop();

        res = front;

        if (front.y == end.y && front.x == end.x)
            break;

        // directions
        for (int i = 0; i < 4; ++i)
        {
            int ny = front.y + dy[i];
            int nx = front.x + dx[i];

            if (ignore)
            {
                if (inRange({ny, nx}) && !visited[ny][nx])
                {
                    visited[ny][nx] = true;
                    res.path.push_back(map[ny][nx]);
                    q.push({ny, nx, res.passed + 1, res.path});
                    res.path.pop_back();
                }
            }
            else
            {
                if (inRange({ny, nx}) && !visited[ny][nx] && map[ny][nx] == 0)
                {
                    visited[ny][nx] = true;
                    res.path.push_back(map[ny][nx]);
                    q.push({ny, nx, res.passed + 1, res.path});
                    res.path.pop_back();
                }
            }
        }
    }
    return res;
}

int main()
{
    cin >> N >> M;

    // for input
    int cnt = 0;
    string input, line;
    while (getline(cin, line))
    {
        input += line;
        cnt++;
        if (cnt > N)
            break;
    }

    // set map
    for (int i = 0; i < input.length(); ++i)
    {
        map[int(i / M)][int(i % M)] = input[i] - '0';
    }

    // check start and end pos
    bool startBlocked = false, endBlocked = false;

    if (isSurrounded({0, 0}))
        startBlocked = true;
    if (isSurrounded({N - 1, M - 1}))
        endBlocked = true;

    if (startBlocked && endBlocked)
        cout << -1;
    else
    {
        // in one line
        vector<int> edgePath = vector<int>();
        DFSEdge({0,0}, edgePath);
        cout << edgePath.size() << "\n";

        vector<int> path = vector<int>();
        pos midPos;
        if (map[int((N - 1) / 2)][int((M - 1) / 2)] != 1)
        {
            midPos = BFS({0, 0, 1, path}, {int((N - 1) / 2), int((M - 1) / 2)}, false);
        }
        else
        {
            midPos = BFS({0, 0, 1, path}, {(N - 1), (M - 1)}, false);
        }

        // cout << midPos.path.size() << "\n";
        // cout << midPos.y << " " << midPos.x << "\n";
        int checkOne = 0;
        pos finalPos = BFS(midPos, {N - 1, M - 1}, true);
        for (int i = 0; i < finalPos.path.size(); ++i)
        {
            if (finalPos.path[i] == 1)
                checkOne++;
        }
        if (canBreak && checkOne == 1)
        {
            cout << finalPos.passed - 2;
        }
        // else if (canBreak && checkOne > 1)
        // {
        //     if (finalPos.y == N - 1 && finalPos.x == M - 1)
        //     {
        //         cout << finalPos.passed - 1;
        //     }
        //     else
        //         cout << -1;
        // }
        else
        {
            cout << finalPos.passed - 1;
        }
    }

    return 0;
}