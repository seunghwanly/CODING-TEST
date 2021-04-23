#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int map[25][25] = {
    0,
};
int visited[25][25] = {
    false,
};

struct pos
{
    int y, x;
};

void DFS(pos pos, int &cnt)
{
    if (map[pos.y][pos.x] == 1)
    {
        map[pos.y][pos.x] = 0;
        cnt++;
        for (int i = 0; i < 4; ++i)
        {
            int nextY = pos.y + dy[i];
            int nextX = pos.x + dx[i];

            if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < N)
            {
                DFS({nextY, nextX}, cnt);
            }
        }
    }
}

int main()
{
    cin >> N;

    int cnt = 0;
    string input;
    string line;
    while (getline(cin, line))
    {
        input += line;
        cnt++;
        if (cnt > N)
            break;
    }

    // to map
    for(int i =0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            map[i][j] = input[i * N + j] == '1' ? 1 : 0;
        }
    }

    // answer
    vector<int> answer;
    int count = 0;
    for(int i =0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            if(map[i][j] == 1) {
                DFS({i,j}, count);
                answer.push_back(count);
                count = 0;
            }
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for(int i=0; i<answer.size(); ++i) {
        cout << answer[i] << "\n";
    }

    return 0;
}
