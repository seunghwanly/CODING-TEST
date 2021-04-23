#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct pos
{
    int y, x;
    int time;
};

pos dpos[8] = {
    // y, x
    {-1, -2}, // top-left-1
    {-2, -1}, // top-left-2
    {-2, 1},  // top-right-2
    {-1, 2},  // top-right-1
    {1, -2},  // down-left-1
    {2, -1},  // down-left-2
    {2, 1},   // down-right-2
    {1, 2},   // down-right-1
};

void BFS(int &l, pos &C, pos &D, int &T, bool (*visited)[300])
{
    queue<pos> q;
    C.time = 0;
    q.push(C);
    visited[C.y][C.x] = true;

    while (!q.empty())
    {
        pos front = q.front();
        q.pop();

        T = front.time;

        if (front.y == D.y && front.x == D.x)
            break;

        for (int i = 0; i < 8; ++i)
        {
            pos npos = {front.y + dpos[i].y, front.x + dpos[i].x, T};
            if (npos.y >= 0 && npos.y < l && npos.x >= 0 && npos.x < l && !visited[npos.y][npos.x])
            {
                npos.time += 1;
                q.push(npos);
                visited[npos.y][npos.x] = true;
            }
        }
    }
}

int main()
{
    int TC;
    cin >> TC;

    vector<int> listL;
    vector<pos> listC, listD;
    pos C, D; // current, destination
    int l; // size
    // test cases
    for (int i = 0; i < TC; ++i)
    {
        cin >> l;
        cin >> C.y >> C.x;
        cin >> D.y >> D.x;

        // save
        listL.push_back(l);
        listC.push_back(C);
        listD.push_back(D);
    }
    for (int i = 0; i < TC; ++i)
    {
        bool visited[300][300] = { false,};
        int T = 0;
        
        // BFS
        BFS(listL[i], listC[i], listD[i], T, visited);

        cout << T << endl;
    }

    return 0;
}