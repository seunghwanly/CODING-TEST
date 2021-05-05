#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int MIN = 1000000000;
int MAX = -1000000000;

int numbers[11] = {
    0,
};
int operators[4] = {
    0,
};

void search(int picked, int result)
{
    if (picked == N)
    {
        if (result > MAX)
            MAX = result;
        if (result < MIN)
            MIN = result;
    }
    else
    {
        for (int i = 0; i < 4; ++i)
        {
            if (operators[i] > 0)
            {
                operators[i]--;
                switch (i)
                {
                case 0:
                    search(picked + 1, result + numbers[picked]);
                    break;
                case 1:
                    search(picked + 1, result - numbers[picked]);
                    break;
                case 2:
                    search(picked + 1, result * numbers[picked]);
                    break;
                case 3:
                    search(picked + 1, result / numbers[picked]);
                    break;
                }
                operators[i]++;
            }
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> numbers[i];
    }
    for (int i = 0; i < 4; ++i)
    {
        cin >> operators[i];
    }

    search(1, numbers[0]);

    cout << MAX << "\n" << MIN << "\n";

    return 0;
}