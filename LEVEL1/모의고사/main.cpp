#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1번 : 1 2 3 4 5              : length = 5
// 2번 : 2 1 2 3 2 4 2 5        : length = 8
// 3번 : 3 3 1 1 2 2 4 4 5 5    : length = 10

vector<int> solution(vector<int> answers)
{
    vector<int> answer;

    int A[5] = {1, 2, 3, 4, 5};
    int B[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int C[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int checkA = 0, checkB = 0, checkC = 0;

    for (int i = 0; i < answers.size(); ++i)
    {
        if (answers[i] == A[i % 5])
            checkA++;
        if (answers[i] == B[i % 8])
            checkB++;
        if (answers[i] == C[i % 10])
            checkC++;
    }

    // check numbers
    int candidates[3] = {checkA, checkB, checkC};

    // insert in order
    int max = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (max <= candidates[i])
            max = candidates[i];
    }
    // remove element
    for (int i = 0; i < 3; ++i)
    {
        if (candidates[i] == max)
            answer.push_back(i + 1);
    }

    return answer;
}

int main()
{

    //example
    vector<int> answers;

    int initAnswers[25] = {1, 2, 2, 4, 5,
                           2, 2, 2, 2, 2,
                           2, 2, 2, 2, 2,
                           2, 2, 2, 2, 2,
                           2, 2, 2, 2, 2}; // 1,3,2,4,2 // 1, 2, 3, 4, 5

    // init
    for (auto a : initAnswers)
        answers.push_back(a);

    // solution
    solution(answers);

    return 0;
}