#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{

    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for (int i = 0; i < participant.size(); ++i)
    {
        if (participant[i] != completion[i])
        {
            answer = participant[i];
            break;
        }
    }

    return answer;
}

int main()
{

    // example
    vector<string> participant;
    vector<string> completion;

    string initParticipant[5] = {"marina", "josipa", "nikola", "vinko", "filipa"}; // "marina", "josipa", "nikola", "vinko", "filipa" // "leo", "kiki", "eden"
    string initCompletion[4] = {"josipa", "filipa", "marina", "nikola"};           // "marina", "josipa", "nikola", "filipa"

    // init
    for (auto p : initParticipant)
        participant.push_back(p);

    for (auto c : initCompletion)
        completion.push_back(c);

    // solution
    solution(participant, completion);

    return 0;
}