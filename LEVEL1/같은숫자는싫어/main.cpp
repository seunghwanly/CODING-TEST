#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    stack<int> s;

    for (auto a : arr)
        if (s.empty() || s.top() != a)
            s.push(a);

    while(!s.empty()) {
        answer.push_back(s.top());
        s.pop();
    }
    reverse(answer.begin(), answer.end());

    return answer;
}

int main()
{

    vector<int> arr;

    // example
    int initArr[7] = {1, 1, 3, 3, 0, 1, 1};

    for (auto i : initArr)
        arr.push_back(i);

    solution(arr);

    return 0;
}