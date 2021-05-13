#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct pos
{
    char c;
    int index;
};

char leftSlice[4] = {'(', '{', '[', '<'};
char rightSlice[4] = {')', '}', ']', '>'};

vector<pos> leftStack;
queue<pos> rightQueue;

int isInside(char c, char arr[4])
{
    int res = -1;
    for (int i = 0; i < 4; ++i)
    {
        if (arr[i] == c)
        {
            res = i;
            break;
        }
    }
    return res;
}

bool isMatch(char leftC, char rightC)
{
    int lIdx = isInside(leftC, leftSlice), rIdx = isInside(rightC, rightSlice);
    if (lIdx == rIdx)
        return true;
    else
        return false;
}

int solution(string inputString)
{
    int answer = 0;

    if (isInside(inputString[0], rightSlice) != -1)
    {
        answer = 0;
    }
    else
    {
        for (int i = 1; i < inputString.length(); ++i)
        {
            if (isInside(inputString[i], leftSlice) != -1)
            {
                leftStack.push_back({inputString[i], i});
            }
            if (isInside(inputString[i], rightSlice) != -1)
            {
                rightQueue.push({inputString[i], i});
            }
        }

        // after
        if (leftStack.size() == rightQueue.size())
        {
            // 잘 사용됐거나 짝이 안맞는 경우
            while (true)
            {
                if(leftStack.size() == 0 && rightQueue.size() == 0) break;
                if (isMatch(leftStack[leftStack.size() - 1].c, rightQueue.front().c))
                {
                    answer++;
                    leftStack.pop_back();
                    rightQueue.pop();
                }
                else
                {
                    answer = rightQueue.front().index * -1;
                    break;
                }
            }
        }
        else if (leftStack.size() > rightQueue.size())
        {
            // 안 닫힌 경우
            if (rightQueue.back().index == inputString.length() - 1)
            {
                answer = (inputString.length() - 1) * (-1);
            }
            else
            {
                answer = rightQueue.front().index * (-1);
            }
        }
        else
        {
            // 닫는 괄호가 먼저 나온 경우
            answer = rightQueue.front().index * (-1);
            // 열린 괄호가 더 적은 경우, 여닫는 괄호의 짝이 맞지 않는 경우
        }
    }

    return answer;
}

int main()
{
    string input = "x * (y + z) ^ 2 = ?";
    cout << solution(input);
    return 0;
}