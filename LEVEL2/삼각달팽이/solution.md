# SOLUTION

처음에는 Object로 코드를 작성했지만, 이내 그럴 필요가 없다고 생각했다. 입력받은 수가 n이라고 하면 삼각형 면을 따라서 움직이므로 한 면에서 이루어지는 연산의 수는 n, n-1, n-2, ... 이런 식으로 구성된다. 예를 들어 입력받은 수가 5(n=5)라고 했을 때 작동하는 순서는 다음과 같다.

[![](https://mermaid.ink/img/eyJjb2RlIjoiZ3JhcGggVERcbiAgICBTVEFSVCAtLT4gfGkgPSBufCBMT09QXG4gICAgTE9PUCAtLT4gfGogPSBpfCBTVUJfTE9PUFxuICAgIFNVQl9MT09QIC0tPiB8XCJsaXN0W2N1cnJlbnRJbmRleCArIDFdID0gY3VycmVudENvdW50XCJ8IENIRUNLKENIRUNLIERJUkVDVElPTilcbiAgICBDSEVDSyAtLT4gTEVGVF9TSURFIFxuICAgIENIRUNLIC0tPiBCRUxPV19TSURFXG4gICAgQ0hFQ0sgLS0-IFJJR0hUX1NJREVcbiAgICBMRUZUX1NJREUgLS0-IFNFVFxuICAgIEJFTE9XX1NJREUgLS0-IFNFVFxuICAgIFJJR0hUX1NJREUgLS0-IFNFVFxuICAgIFNFVCAtLT4gU1VCX0xPT1BfRihDSEVDSyBTVUJfTE9PUClcbiAgICBTVUJfTE9PUF9GIC0tPiB8aiAtIDF8IFNVQl9MT09QXG4gICAgU1VCX0xPT1BfRiAtLT4gU1VCX0xPT1BfRE9ORVxuICAgIFNVQl9MT09QX0RPTkUgLS0-IHxpIC0gMXwgTE9PUFxuICAgIFNVQl9MT09QX0RPTkUgLS0-IExPT1BfRE9ORSBcbiAgICBMT09QX0RPTkUgLS0-IHJldHVybiIsIm1lcm1haWQiOnsidGhlbWUiOiJkZWZhdWx0In0sInVwZGF0ZUVkaXRvciI6ZmFsc2V9)](https://mermaid-js.github.io/mermaid-live-editor/#/edit/eyJjb2RlIjoiZ3JhcGggVERcbiAgICBTVEFSVCAtLT4gfGkgPSBufCBMT09QXG4gICAgTE9PUCAtLT4gfGogPSBpfCBTVUJfTE9PUFxuICAgIFNVQl9MT09QIC0tPiB8XCJsaXN0W2N1cnJlbnRJbmRleCArIDFdID0gY3VycmVudENvdW50XCJ8IENIRUNLKENIRUNLIERJUkVDVElPTilcbiAgICBDSEVDSyAtLT4gTEVGVF9TSURFIFxuICAgIENIRUNLIC0tPiBCRUxPV19TSURFXG4gICAgQ0hFQ0sgLS0-IFJJR0hUX1NJREVcbiAgICBMRUZUX1NJREUgLS0-IFNFVFxuICAgIEJFTE9XX1NJREUgLS0-IFNFVFxuICAgIFJJR0hUX1NJREUgLS0-IFNFVFxuICAgIFNFVCAtLT4gU1VCX0xPT1BfRihDSEVDSyBTVUJfTE9PUClcbiAgICBTVUJfTE9PUF9GIC0tPiB8aiAtIDF8IFNVQl9MT09QXG4gICAgU1VCX0xPT1BfRiAtLT4gU1VCX0xPT1BfRE9ORVxuICAgIFNVQl9MT09QX0RPTkUgLS0-IHxpIC0gMXwgTE9PUFxuICAgIFNVQl9MT09QX0RPTkUgLS0-IExPT1BfRE9ORSBcbiAgICBMT09QX0RPTkUgLS0-IHJldHVybiIsIm1lcm1haWQiOnsidGhlbWUiOiJkZWZhdWx0In0sInVwZGF0ZUVkaXRvciI6ZmFsc2V9)


1) LEFT_SIDE
2) BELOW_SIDE
3) RIGHT_SIDE

```
n :    5   4   3   2   1
D :    L   B   R   L   B
```

2중 loop를 사용해서 왼쪽 면(⬇) 부터 시작해서 밑(➡), 그리고 오른쪽(⬆) 순서대로 작업을 하게된다. 처음에 입력받은 n이 5이므로, list에 값을 넣는 것은 5번 진행하되 마지막 j가 1일 경우에는 방향을 틀어주어야한다. 그래서 방향을 설정해주는 작업을 해주었다. 

```js
        // turn direction
            if (j !== 1) {
                // check direction
                if (currentDirectionIndex === 2) {
                    // left_side
                    currentIndex += currentHeight;
                    currentHeight += 1;
                } else if (currentDirectionIndex === 1) {
                    // below
                    currentIndex += 1;
                } else {
                    // right_side
                    currentIndex -= currentHeight;
                    currentHeight -= 1;
                }
            } else {
                // check direction
                if (currentDirectionIndex === 2) {
                    // left_side >>> to below
                    currentIndex += 1;
                } else if (currentDirectionIndex === 1) {
                    // below >>> to right_side
                    currentIndex -= currentHeight;
                    currentHeight -= 1;
                } else {
                    // right_side >>> to left_side
                    currentIndex += currentHeight;
                    currentHeight += 1;
                }
            }
```

1) LEFT_SIDE<br>
    삼각형에서 왼쪽 면을 타고 내려갈 때 index는 자신의 layer 층 높이 만큼 더하면 다음 index값이 나오게된다.
    ```
                    1
                2       3
            4       5       6
        7       8       9       10
    11      12      13      14      15
    ```
    LEFT_SIDE인 경우는 1 →(+1)→ 2 →(+2)→ 4 →(+3)→ 7 →(+4)→ 11 가 성립한다. 이때 1에서 출발할 때 1의 높이가 1이라고 가정할 때, 1(+1) 해서 다음 index는 2가 된다. 
    > 위와 같은 index를 가진 트리구조에서 진행한다는 가정이다. 
2) BELOW_SIDE<br>
    가장 밑단인 경우에는 +1 만 해주면 아래면이 채워진다. 이때 j가 1인 경우에는 다시 위로 올라가야하므로 15 →(-5)→ 10 과 같이 현재 index의 높이만큼 빼주게되면 다음 index가 나온다. 
3) RIGHT_SIDE<br>
    오른쪽에서 위로 올라가는 경우는 10 →(-4)→ 6 과 같이 진행되면 j가 1인 경우에는 다시 왼쪽으로 내려가야하므로 현재 index의 높이만큼 더해주게되면 다음 index가 나온다. 

### 방향 순서대로 자동 전환
```js
if (currentDirectionIndex > 0) currentDirectionIndex--;
else currentDirectionIndex = 2;
```

마지막으로는 list를 반환할 때 맨 앞의 원소는 empty이므로 slice( )를 통해서 반환을 해주었다. 