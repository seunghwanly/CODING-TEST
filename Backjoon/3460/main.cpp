#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int T, n;
vector<int> bin;

void toBinary()
{
    int k = n;
    // int r = findMax();
    int r = int(floor(sqrt(n)));

    while (r > -1)
    {
        if (k >= pow(2, r))
        {
            k -= int(pow(2, r));
            bin.push_back(r);
        }
        r--;
    }
}

int main()
{
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        cin >> n;
        toBinary();
        reverse(bin.begin(), bin.end());
        for (int k = 0; k < bin.size(); ++k)
        {
            cout << bin[k] << " ";
        }
        cout << "\n";
        bin.clear();
    }
    return 0;
}