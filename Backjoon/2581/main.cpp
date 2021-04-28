#include <iostream>
#include <cmath>

using namespace std;

int M, N;

bool isPrime(int num)
{
    if (num == 1)
        return false;
    if (num <= 3)
        return true;
    bool res = true;
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
        {
            res = false;
            break;
        }
    }
    return res;
}

int main()
{
    cin >> M >> N;

    int min = -1, sum = 0;
    for (int i = M; i <= N; ++i)
    {
        if (isPrime(i))
        {
            if (min == -1)
                min = i;
            sum += i;
        }
    }
    if (sum > 0)
        cout << sum << "\n"
             << min;
    else
        cout << -1;

    return 0;
}