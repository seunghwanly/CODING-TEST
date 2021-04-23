#include <iostream>
#include <vector>

using namespace std;

int S[13];
int P[6];

void DFS(int sIdx, int pIdx, int testcase)
{
    if (pIdx == 6)
    {
        for (int i = 0; i < 6; ++i)
        {
            cout << P[i] << " ";
        }
        cout << "\n";
        return;
    }

    // 입력받은 S로부터 P로 옮겨담기
    // S의 0번째, 입력받은 순서부터 시작
    // P의 0부터 로또 번호 6개 채워넣기
    for (int i = sIdx; i < testcase; ++i)
    {
        P[pIdx] = S[i];
        DFS(i + 1, pIdx + 1, testcase);
    }
}

int main()
{

    int testcase;

    while (cin >> testcase)
    {
        if (testcase == 0)
            break;

        for (int i = 0; i < testcase; ++i)
        {
            int input;
            cin >> input;
            S[i] = input;
        }

        // DFS
        DFS(0, 0, testcase);
        cout << "\n";
    }

    return 0;
}