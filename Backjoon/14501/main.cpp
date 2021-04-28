#include <iostream>
#include <vector>

using namespace std;

int N, answer;

int days[16];
int prices[16];

void DFS(int curr, int totalPrice)
{
    if (curr >= N + 1)
    {
        if (answer < totalPrice)
            answer = totalPrice;
        return;
    }

    if (curr + days[curr] <= N + 1)
    {
        DFS(curr + days[curr], totalPrice + prices[curr]);
    }
    if (curr + 1 <= N + 1)
    {
        DFS(curr + 1, totalPrice);
    }
}

int main()
{

    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        int t, p;
        cin >> t >> p;
        days[i] = t;
        prices[i] = p;
    }
    DFS(1, 0);
    cout << answer;

    return 0;
}