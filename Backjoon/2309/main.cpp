#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int N[7];
int C[9];
int currentWeight;

int main()
{
    for (int i = 0; i < 9; ++i)
    {
        cin >> C[i];
        currentWeight += C[i];
    }
    int loss = currentWeight - 100;
    sort(C, C + 9);
    int idx1, idx2;
    for (int i = 0; i < 8; ++i)
    {
        bool out = false;
        for (int j = i + 1; j < 9; ++j)
        {
            if (C[i] + C[j] == loss)
            {
                idx1 = i;
                idx2 = j;
                out = true;
                break;
            }
            if (out)
                break;
        }
    }
    for (int i = 0, j = 0; i < 9; ++i)
    {
        if (i != idx1 && i != idx2)
        {
            N[j] = C[i];
            j++;
        }
    }
    for (int i = 0; i < 7; ++i)
        cout << N[i] << "\n";

    return 0;
}