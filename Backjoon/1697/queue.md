# BFS
너비를 우선으로 하여 탐색하는 알고리즘이다. **최단 경로**를 찾아준다는 의미로 많이 사용되는 알고리즘인데, 이는 **Queue**로 구현이 가능하다.

아래 코드는 8개의 원소로 트리가 구현되어 있다고 가정한다.

```c++
#include <iostream>

using namespace std;

int map[][];    // [각 노드][노드의 자식]
bool visit[8]; //방문한 노드 상태

void BFS() {
    queue<int> q;

    // init first element
    q.push(map[0][0]); // q.push(start);
    visit[map[0][0]] = true;

    while(!q.empty()) {
        int tempNode = q.front();
        // front pop
        q.pop();
        // check children
        for(int i=0; i<map[tempNode].size(); ++i) {
            // not visited before
            if(!visit[map[tempNode][i]]) {
                // make visit
                q.push(map[tempNode][i]);
                visit[map[tempNode][i]] = true;
            }
        }
    }
}
```

[![](https://mermaid.ink/img/eyJjb2RlIjoiZ3JhcGggVERcbiAgICBpMSgoMSkpIC0tPiBpMigoMikpXG4gICAgaTEoKDEpKSAtLT4gaTMoKDMpKVxuICAgIGkyKCgyKSkgLS0-IGk0KCg0KSlcbiAgICBpMigoMikpIC0tPiBpNSgoNSkpXG4gICAgaTMoKDMpKSAtLT4gaTYoKDYpKVxuICAgIGkzKCgzKSkgLS0-IGk3KCg3KSlcbiAgICBpNCgoNCkpIC0tPiBpOCgoOCkpXG5cbiIsIm1lcm1haWQiOnt9LCJ1cGRhdGVFZGl0b3IiOmZhbHNlfQ)](https://mermaid-js.github.io/mermaid-live-editor/#/edit/eyJjb2RlIjoiZ3JhcGggVERcbiAgICBpMSgoMSkpIC0tPiBpMigoMikpXG4gICAgaTEoKDEpKSAtLT4gaTMoKDMpKVxuICAgIGkyKCgyKSkgLS0-IGk0KCg0KSlcbiAgICBpMigoMikpIC0tPiBpNSgoNSkpXG4gICAgaTMoKDMpKSAtLT4gaTYoKDYpKVxuICAgIGkzKCgzKSkgLS0-IGk3KCg3KSlcbiAgICBpNCgoNCkpIC0tPiBpOCgoOCkpXG5cbiIsIm1lcm1haWQiOnt9LCJ1cGRhdGVFZGl0b3IiOmZhbHNlfQ)

위 코드를 순서대로 진행하면
```cpp
...
[1][2, 3]
[2][4, 5]
[3][6, 7]
[4][8]
...
```
위 배열을 순환하면서 1번부터 8번까지 순차적으로 탐색을 하게 된다.

앞으로 BFS를 구현하려면 위 코드를 응용해서 구현하는데에는 큰 어려움은 없을 것으로 생각된다.