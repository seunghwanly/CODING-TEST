#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int n;

int main()
{

    cin >> n;

    int cnt = 0;
    vector<string> input;
    string line;
    while (getline(cin, line))
    {
        input.push_back(line);
        cnt++;
        if (cnt > n)
            break;
    }

    for (int i = 1; i < n + 1; ++i)
    {
        if (input[i].size() == 1)
        {
            cout << "Yes\n";
        }
        else
        {
            stack<char> front;
            stack<char> back;
            for (int j = 0, k = input[i].size() - 1; j < k; ++j, --k)
            {
                front.push(input[i][j]);
                back.push(input[i][k]);
            }
            string result = "No";
            if (front.size() == back.size())
            {
                while (!front.empty())
                {
                    // to lower case
                    int frontASCII = char(front.top());
                    int backASCII = char(back.top());
                    if (frontASCII >= 65 && frontASCII <= 90)
                    {
                       frontASCII += 32;
                    }
                    if (backASCII >= 65 && backASCII <= 90)
                    {
                        backASCII += 32;
                    }
                    // cout << frontASCII << " " << backASCII <<endl;
                    if (frontASCII == backASCII)
                    {
                        front.pop();
                        back.pop();
                    }
                    else
                        break;
                }
                if (front.size() == 0)
                {
                    result = "Yes";
                }
            }
            cout << result << endl;
        }
    }

    return 0;
}