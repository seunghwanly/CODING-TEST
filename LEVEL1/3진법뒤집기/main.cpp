#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int solution(int n)
{
    int answer = 0;

    vector<int> ternary;
    int factor = 0;

    // get factor
    while(true) {
        int value = pow(3, factor);
        if(value > n) {
            --factor;
            break;
        }
        ++factor;
    }
    // into ternary
    for(int i = factor; i >=0; --i) {
        int quotient = n / pow(3, i);
        ternary.push_back(quotient);
        n = n - quotient * pow(3,i);
    }
    // reverse
    reverse(ternary.begin(), ternary.end());
    // to decimal
    for(int i=0; i<ternary.size(); ++i) {
        answer += ternary[i] * pow(3, ternary.size() - 1 - i);
    }
    
    return answer;
}

int main()
{

    int n = 45;

    solution(n);

    return 0;
}