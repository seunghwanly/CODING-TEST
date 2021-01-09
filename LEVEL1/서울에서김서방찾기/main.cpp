#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    for(int i; i < seoul.size(); ++i) {
        if(seoul[i].compare("Kim") == 0) {
            answer.append("김서방은 ").append(to_string(i)).append("에 있다");        
        } 
    }

    return answer;
}

int main() {

    vector<string> seoul;

    string initSeoul[2] = {"Jane", "Kim"};

    for(auto i : initSeoul)
        seoul.push_back(i);

    solution(seoul);

    return 0;
}