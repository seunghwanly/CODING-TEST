#include <iostream>

using namespace std;

int N, K; // 1 <= N <= 10000, 1 <= K <= N
int d[10000];

int main()
{
    cin >> N >> K;

    for (int i = 1, j = 0; i <= N; ++i)
    {
        if (N % i == 0)
        {
            d[j] = i;
            j++;
        }
    }
    cout << d[K - 1];
}