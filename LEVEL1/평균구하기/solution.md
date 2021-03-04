## reduce( )
reduce()는 빈 요소를 제외하고 배열 내에 존재하는 각 요소에 대해 callback 함수를 한 번씩 실행하는데, 콜백 함수는 다음의 네 인수를 받습니다:

* accumulator
* currentValue
* currentIndex
* array

예를 들어서
```js
array.reduce((a,b)=> a+b);
```
위와 같이 코드를 작성하게되면 모든 배열의 원소를 더한 값이 반환된다. 유용하게 쓰일 함수로 보인다. 