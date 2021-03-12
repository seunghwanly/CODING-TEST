# SOLUTION

index.js 를 보면 function solution(numbers)는 원래 풀어보려던 코드이지만 굉장히 복잡하고, 1의자리, 10의자리, 100의자리, 1000의자리를 각각 비교하려고 했었다. 의식의 흐름대로 코드를 작성해서 코드가 좋지 않다.

예외 케이스를 발견하지 못해서 [질문하기]를 들어가서 예외코드를 찾아보다가 **Jinha Hwang**님의 질문을 보고 코드를 살펴보았다. 코드를 약간 추가하였는데 코드는 다음과 같다.

```js
    function solution(numbers) {
        numbers.sort((a,b) => ''+a+b>''+b+a ? -1 : 1)

        if(numbers.every(val => val === 0)) return '0';

        return numbers.reduce((acc, curr) => acc+curr, '')
    }
```


## 코드풀이

```js
        numbers.sort((a,b) => ''+a+b>''+b+a ? -1 : 1)
```
이 부분은 간단하게 표현되었다. BubbleSort 처럼 진행이 되는데, prev element와 current element를 두가지 경우를 비교하여 더 큰 값으로 정렬을 하기 때문에, 먼저 원소들을 하나하나 Number로 가져와 정렬을 진행한다.

다음 if문은 모든 값이 0일 때 예외적인 경우를 처리해주기 위해서 한 것이다.

마지막 반환때는 표시하면 다음과 같이 표시할 수 있다. 
```js
[0][1][2][3][4] ... [curr][curr+1][curr+2] ...
```
라고 할 때, acc는 0부터 4까지 ''로 join이 된 것과 같다. 그리고 이 작업을 마지막까지 진행을 해주게되면 결국 반환되는 값은 string이기 때문에 정답으로 인정이된다. 

간단하게 생각을 할 수 없었던 것 같고, sort 함수 내에서 다양하게 작업을 할 수 있다는 것을 잊으면 안될 것 같다. 

<p align='end'><em>-2021/03/12 가장큰수</em></p>