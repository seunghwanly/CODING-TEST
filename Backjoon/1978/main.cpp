#include <iostream>
#include <cmath>

using namespace std;

int N, cnt = 0;
int numbers[100];

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if ((n % i) == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> numbers[i];
        if (isPrime(numbers[i]))
            cnt++;
    }
    cout << cnt;
    return 0;
}