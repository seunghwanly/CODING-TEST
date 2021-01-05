#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor)
{
    vector<int> answer;

    for (auto a : arr)
    {
        if (a % divisor == 0)
        {
            answer.push_back(a);
        }
    }

    sort(answer.begin(), answer.end());

    if (answer.size() == 0)
        answer.push_back(-1);

    return answer;
}

int main()
{

    vector<int> arr;
    int divisor;

    // example
    int initArr[4] = {5, 9, 7, 10};
    divisor = 5;

    for (auto a : initArr)
        arr.push_back(a);

    solution(arr, divisor);

    return 0;
}