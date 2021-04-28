#include <iostream>

using namespace std;

int A, B;

int DFS(int begin, int end, int count, int res)
{
    if (count == end)
        return res;
    for (int i = 0; i < begin; ++i)
    {
        if (count == end)
            break;
        res += begin;
        count += 1;
    }
    return DFS(begin + 1, end, count, res);
}

int main()
{

    cin >> A >> B;

    cout << DFS(1, B, 0, 0) - DFS(1, A - 1, 0, 0);

    return 0;
}