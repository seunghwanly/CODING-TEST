#include <iostream>
#define MIN(A, B) A > B ? B : A

using namespace std;

int N, M;

int gcd(int min)
{
    int res = 0;
    int cnt = 1;
    while (cnt <= min)
    {
        if (N % cnt == 0 && M % cnt == 0)
        {
            res = cnt;
        }
        cnt++;
    }
    return res;
}
int lcm(int min)
{
    return gcd(min) * int(N / gcd(min)) * int(M / gcd(min));
}

int main()
{

    cin >> N >> M;

    cout << gcd(MIN(N, M)) << "\n"
         << lcm(MIN(N, M));

    return 0;
}