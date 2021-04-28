#include <iostream>

using namespace std;

int on, in, out, maxP = -1;

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        cin >> out >> in;
        on = (i == 0) ? on + in : on - out + in;
        if (maxP < on)
            maxP = on;
    }
    cout << maxP;
    return 0;
}