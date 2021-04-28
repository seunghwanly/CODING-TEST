#include <iostream>

using namespace std;
int N;
int fibonacci(int k)
{
    if (k == 0)
        return 0;
    if (k <= 2)
        return 1;
    return fibonacci(k - 2) + fibonacci(k - 1);
}
int main()
{
    cin >> N;
    cout << fibonacci(N);
    return 0;
}