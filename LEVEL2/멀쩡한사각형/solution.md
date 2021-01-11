# SOLUTION

> 서승현 , 탈퇴한 사용자 , KyoungDuckKim , rocks , 전대식 님의 풀이

```js
function solution(w,h){
    const gcd = (a, b) => {
        return b === 0 ? a : gcd(b, a % b);
    };

    return w * h - (w + h - gcd(w, h));
}
```
>> 김재훈―2020.09.07 14:47 님의 해설

    1. 사각형의 w와 h가 서로소인 경우 잘린 정사각형의 갯수 = w + h - 1<br>
    2. 사각형에서 서로소 관계의 사각형의 갯수 = 최대공약수<br>
    3. 잘린 정사각형의 개수는 g * ((w' / g) + (h'/g) - 1) = w'+ h' - g<br>

<em>*서로소 : 두 수 사이의 관계가 1 이외에 공약수가 없는 수</em><br>

### 😀 w' : 사각형의 가로길이, h' : 사각형의 세로길이<br>
</p>
