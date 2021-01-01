#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;

    for (int i = 0; i < numbers.size(); ++i)
    {
        for (int j = i + 1; j < numbers.size(); ++j)
        {
            int check = numbers[i] + numbers[j];
            bool isInArray = false;
            for (auto num : answer)
            {
                if (num == check)
                    isInArray = true;
            }
            if (!isInArray)
            {
                answer.push_back(check);
            }
        }
    }
    // sort
    for (int i = 0; i < answer.size(); ++i)
    {
        for (int j = i + 1; j < answer.size(); ++j)
        {
            if (answer[i] > answer[j])
            {
                int temp = answer[i];
                answer[i] = answer[j];
                answer[j] = temp;
            }
        }
    }

    return answer;
}

int main()
{

    vector<int> numbers;

    int init_numbers[5] = {2, 1, 3, 4, 1};

    for (auto num : init_numbers)
        numbers.push_back(num);

    solution(numbers);

    return 0;
}