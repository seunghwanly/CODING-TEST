#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int> > commands)
{
    vector<int> answer;
    /* 
        i = start
        j = end
        k = index
    */

    for (int loop = 0; loop < commands.size(); ++loop)
    { // y 축
        //get i, j, k
        int i, j, k;
        i = commands[loop][0] - 1;
        j = commands[loop][1] - 1;
        k = commands[loop][2] - 1;
        // temp vector
        vector<int> temp;
        for (int l = i; l <= j; ++l)
        {
            temp.push_back(array[l]);
        } //saved
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k]);
    }

    return answer;
}

int main()
{

    // example
    vector<int> array;
    vector<vector<int> > commands;

    int initArray[7] = {1, 5, 2, 6, 3, 7, 4};
    int initCommands[3][3] = {{2, 5, 3},
                              {4, 4, 1},
                              {1, 7, 3}};

    // init
    for (auto a : initArray)
        array.push_back(a);

    for (int i = 0; i < 3; ++i)
    {
        vector<int> temp;
        for (int j = 0; j < 3; ++j)
        {
            temp.push_back(initCommands[i][j]);
        }
        commands.push_back(temp);
    }

    //solution
    solution(array, commands);

    return 0;
}