#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n)
{
    vector<string> answer;

    for (int i = 0; i < strings.size(); ++i)
    {
        for (int j = i + 1; j < strings.size(); ++j)
        {
            if (strings[i][n] > strings[j][n])
            {
                string temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
            else if (strings[i][n] == strings[j][n])
            {
                if (strings[i] > strings[j])
                {
                    string temp = strings[i];
                    strings[i] = strings[j];
                    strings[j] = temp;
                }
            }
        }
    }

    for (auto s : strings)
        answer.push_back(s);

    return answer;
}

int main()
{
    vector<string> strings;
    int n;
    string initStrings[3] = {"abce", "abcd", "cdx"};
    for (auto s : initStrings)
        strings.push_back(s);
    n = 2;
    solution(strings, n);

    return 0;
}