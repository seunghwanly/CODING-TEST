#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 2016/01/01 -> FRI
/*
    1월 1일을 기준 시점으로 하고 특정 날짜까지의 날 수 를 계산한 다음 7로 나눈 나머지 값에 의해서 요일을 알 수 있음
*/
string solution(int a, int b)
{
    string answer = "";
    // days
    string days[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int months[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // sum up days
    int numOfDays = (2015) * 365 + (2015 / 4 - 2015 / 100 + 2015 / 400);
    for (int i = 0; i < a - 1; ++i)
        numOfDays += months[i];
    numOfDays += b;
    answer = days[numOfDays % 7];
    return answer;
}

int main()
{

    // example
    int a = 5;
    int b = 24;

    // solution
    solution(5, 24);

    return 0;
}