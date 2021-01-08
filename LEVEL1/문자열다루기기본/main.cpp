#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;

    // 48 ~ 57
    for(auto s : s) {
        if(!((int)s >= 48 && (int)s <= 57)) answer = false;
    }
    if(!(s.length() == 4 || s.length() == 6)) answer = false;
    
    return answer;
}

int main() {

    string s = "a234";

    solution(s);

    return 0;
}