#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct block
{
    char c;
    int pos;
};

char S[2] = {'(', ')'};
char M[2] = {'{', '}'};
char B[2] = {'[', ']'};

bool inArr(char arr[], char find)
{
    for (int i = 0; i < 2; ++i)
    {
        if (arr[i] == find)
        {
            return true;
        }
    }
    return false;
}
bool isLeft(char arr[], char find)
{
    int index = -1;
    for (int i = 0; i < 2; ++i)
    {
        if (arr[i] == find)
        {
            index = i;
        }
    }
    return index % 2 == 0;
}

bool inOrder(stack<block> s, char ca[])
{
    stack<int> l;
    stack<int> r;

    while (!s.empty())
    {
        if (s.top().c == ca[0])
            l.push(s.top().pos);
        else
            r.push(s.top().pos);
        s.pop();
    }
    if (l.size() != r.size())
        return false;
    else
    {
        int cnt = 0;
        int lsize = l.size();
        while (!l.empty() && !r.empty())
        {
            if (l.top() > r.top())
                return false;
            else
                cnt++;
            l.pop(); r.pop();
        }
        if(cnt == lsize) return true;
    }
}

bool check(string s)
{
    stack<block> spos;
    stack<block> mpos;
    stack<block> bpos;

    for (int i = 0; i < s.length(); ++i)
    {
        if (inArr(S, s[i]))
        {
            block temp = {s[i], i};
            spos.push(temp);
        }
        if (inArr(M, s[i]))
        {
            block temp = {s[i], i};
            mpos.push(temp);
        }
        if (inArr(B, s[i]))
        {
            block temp = {s[i], i};
            bpos.push(temp);
        }
    }
    //cout << inOrder(spos, S) << " " << inOrder(mpos, M) << " " << inOrder(bpos, B) << endl;
    return inOrder(spos, S) && inOrder(mpos, M) && inOrder(bpos, B);
}

int solution(string s)
{
    int answer = 0;
    if (s.length() % 2 != 0)
        return 0;
    for (int i = 0; i < s.length(); ++i)
    {
        string temp = s;
        string sub = s.substr(0, i);
        temp.erase(0, i);
        temp.append(sub);

        //cout << temp << "\t ";

        if (check(temp))
            answer++;
    }

    return answer;
}

int main()
{

    string s = "())()(";

    cout << solution(s) << endl;

    return 0;
}