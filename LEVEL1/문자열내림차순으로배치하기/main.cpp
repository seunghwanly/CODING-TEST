#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    answer = s;
    
    return answer;
}

int main() {
    string s = "Zbcdefg";

    solution(s);

    return 0;
}