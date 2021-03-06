#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;

    int start = a >= b ? b : a;
    int end = a >= b ? a : b;

    for(int i=start; i<=end; ++i) answer += i;

    return answer;
}

int main() {

    solution(5,3);

    return 0;
}