#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;

    for (int i = 0; i < lost.size(); ++i)
    {
        for (int j = 0; j < reserve.size(); ++j)
        {
            if (lost[i] == reserve[j])
            {
                lost[i] = 0;
                reserve[j] = 0;
            }
        }
    }

    for (int i = 0; i < lost.size(); ++i)
    {
        for (int j = 0; j < reserve.size(); ++j)
        {
            if (lost[i] - 1 > 0 && reserve[j] > 0 && lost[i] - 1 == reserve[j] || lost[i] + 1 == reserve[j])
            {
                lost[i] = 0;
                reserve[j] = 0;
            }
        }
    }

    for (auto n : lost)
    {
        if (n != 0)
            answer++;
    }

    answer =  n - answer;

    return answer;
}

int main()
{

    vector<int> lost;
    vector<int> reserve;
    int n;

    // example
    int initLost[2] = {1, 2};
    int initReserve[2] = {2, 3};
    int initN = 3;

    // init
    for (auto l : initLost)
        lost.push_back(l);
    for (auto r : initReserve)
        reserve.push_back(r);

    n = initN;

    // solution
    solution(n, lost, reserve);

    return 0;
}