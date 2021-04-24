#include <iostream>
#include <queue>

using namespace std;

int N, K, T;
int visited[200001] = {false,};

struct pos {
    int x, time;
};

void BFS() {
    queue<pos> q;
    q.push({N, 0});
    visited[N] = true;

    while (!q.empty())
    {
        pos front = q.front();
        q.pop();

        T = front.time;
        int curr = front.x;
        
        if(front.x == K) break;
        
        // 2x
        if(curr * 2 < 100001 && !visited[curr * 2]) {
            visited[curr * 2] = true;
            q.push({curr * 2, T});
        }
        // x -1
        if(curr - 1 >= 0 && !visited[curr - 1]) {
            visited[curr - 1] = true;
            q.push({curr - 1, T + 1});
        }
        // x + 1
        if(curr + 1 < 100001 && !visited[curr + 1]) {
            visited[curr + 1] = true;
            q.push({curr + 1, T + 1});
        }
    }
}

int main() {
    cin >> N >> K;
    BFS();
    cout << T;
}