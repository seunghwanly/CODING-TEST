#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";

    int idx = s.length() / 2;

    if (s.length() % 2 == 0) {
        vector<char> temp;
        temp.push_back(s[idx - 1]);
        temp.push_back(s[idx]);
        string tempString(temp.begin(), temp.end());
        answer = tempString;
    }
    else
        answer = s[idx];

    return answer;
}

int main()
{

    string s = "qwer";

    solution(s);

    return 0;
}