#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs)
{
    vector<int> res = vector<int>();
    for (int i = 0; i < absolutes.size(); ++i)
    {
        res.push_back(absolutes[i] * (signs[i] ? 1 : (-1)));
    }
    int sum = 0;
    for (int i = 0; i < res.size(); ++i)
    {
        sum += res[i];
    }
    return sum;
}

int main()
{

    vector<int> abs = vector<int>();
    abs.push_back(4);
    abs.push_back(7);
    abs.push_back(12);
    vector<bool> sgn = vector<bool>();
    sgn.push_back(true);
    sgn.push_back(false);
    sgn.push_back(true);

    cout << solution(abs, sgn) << endl;
    return 0;
}