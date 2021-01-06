#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p = 0, y = 0;
    for (auto i : s)
    {
        if ((int)i == 80 || (int)i == 112)
            p++;
        else if ((int)i == 89 || (int)i == 121)
            y++;
    }
    if(p!=y) answer = false;

    return answer;
}

int main()
{

    // example
    string s = "pPoooyY";

    solution(s);

    return 0;
}