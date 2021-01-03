# SOLUTION

'2016년' 위 문제는 오로지 2016년 한 해에 대해서만 다룬다. 

다른 년도에서도 <b>요일</b>에 대해서 구하는 문제라면 모두 공통점이 있다. 

구하는 방식은 아래와 같다.

## 공식
~~~
1월 1일을 기준 시점으로 하고 특정 날짜까지의 날 수 를 계산한 다음,
7로 나눈 나머지 값에 의해서 요일을 알 수 있음
~~~
<ol>
<li>특정 날짜까지의 날 수(days)를 계산</li>
<li>7로 나누어 나머지 값을 구함</li>
</ol>

```c++
// years
int numOfDays = (year-1) * 365 + ((year-1) / 4 - (year-1) / 100 + (year-1) / 400);
// months
    for (int i = 0; i < a - 1; ++i)
        numOfDays += months[i];
// days
    numOfDays += b;
// answer
    answer = days[numOfDays % 7];
```