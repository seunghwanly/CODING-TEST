#include <iostream>
#include <queue>
#include <string>
#define MAX 1000

using namespace std;

int N, M; // row, column

int map[MAX + 1][MAX + 1] = {
    0,
};
int visited[MAX + 1][MAX + 1][2];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct pos
{
    int y, x;
};

bool inRange(pos p)
{
    return p.y >= 0 && p.y < N && p.x >= 0 && p.x < M;
}

int BFS()
{
    queue<pair<pos, int>> q;
    q.push({{0, 0}, 1});
    visited[0][0][1] = 1;

    while (!q.empty())
    {
        pos front = q.front().first;
        int block = q.front().second;
        q.pop();

        if (front.y == N - 1 && front.x == M - 1)
        {
            return visited[front.y][front.x][block];
        }

        for (int i = 0; i < 4; ++i)
        {
            int ny = front.y + dy[i];
            int nx = front.x + dx[i];

            if (inRange({ny, nx}))
            {
                if (map[ny][nx] == 1 && block)
                {
                    cout << "["<<ny<<"] ["<<nx<<"] > "<<block<<"\n";
                    visited[ny][nx][block - 1] = visited[front.y][front.x][block] + 1;
                    q.push({{ny, nx}, block - 1});
                }
                if (map[ny][nx] == 0 && visited[ny][nx][block] == 0)
                {
                    visited[ny][nx][block] = visited[front.y][front.x][block] + 1;
                    q.push({{ny, nx}, block});
                }
            }
        }
    }
    return -1;
}

int main()
{
    cin >> N >> M;

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

    // for(int i=0; i<N; i++) {
    //     for(int j=0; j<M; ++j) {
    //         cout << map[i][j] << " ";
    //     }cout << "\n";
    // }

    cout << BFS();

    return 0;
}

// 8 8
// 01000100
// 01010100
// 01010100
// 01010100
// 01010100
// 01010100
// 01010100
// 00010100
// >> 29

// 5 10
// 0000011000
// 1101011010
// 0000000010
// 1111111110
// 1111000000
// >> 14

// 5 5
// 01100
// 01000
// 01110
// 01000
// 00010
// >> 9