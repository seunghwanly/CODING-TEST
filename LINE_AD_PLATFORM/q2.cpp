#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> array)
{
    vector<int> answer;

    for (int i = 0; i < array.size(); ++i)
    {
        // start
        if (i == 0)
        {
            bool isFound = false;
            for (int j = i + 1; j < array.size(); ++j)
            {
                if (array[i] < array[j])
                {
                    isFound = true;
                    answer.push_back(j);
                    break;
                }
            }
            if (!isFound)
                answer.push_back(-1);
        }
        // end
        else if (i == array.size() - 1)
        {
            bool isFound = false;
            for (int j = i - 1; j >= 0; --j)
            {
                if (array[j] > array[i])
                {
                    isFound = true;
                    answer.push_back(j);
                    break;
                }
            }
            if (!isFound)
                answer.push_back(-1);
        }
        // middle
        else
        {
            int leftMaxIndex = -1, rightMaxIndex = -1;
            for (int l = i - 1; l > -1; --l)
            {
                // left
                if (leftMaxIndex == -1 && array[l] > array[i])
                {
                    leftMaxIndex = l;
                    break;
                }
            }
            for (int r = i + 1; r < array.size(); ++r)
            {
                // right
                if (rightMaxIndex == -1 && array[r] > array[i])
                {
                    rightMaxIndex = r;
                    break;
                }
            }

            // cout << array[i] << " " << i << " | " << leftMaxIndex << " " << rightMaxIndex << "\n";

            if (leftMaxIndex != -1 && rightMaxIndex != -1)
            {
                int leftGap = abs(leftMaxIndex - i);
                int rightGap = abs(rightMaxIndex - i);
                if (leftGap > rightGap)
                {
                    answer.push_back(rightMaxIndex);
                }
                else
                {
                    answer.push_back(leftMaxIndex);
                }
            }
            else if (leftMaxIndex == -1 && rightMaxIndex == -1)
            {
                answer.push_back(-1);
            }
            else
            {
                int index = array[leftMaxIndex] > array[rightMaxIndex] ? leftMaxIndex : rightMaxIndex;
                answer.push_back(index);
            }
        }
    }

    return answer;
}

int main()
{

    vector<int> arr = {3, 5, 4, 1, 2};

    vector<int> d = solution(arr);
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << d[i] << " ";
    }
    return 0;
}