
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
def solution(n, words):

    flag = 1
    lap = 1
    visited = []

    while words:
        front = words.pop(0)
        # flag update
        if flag == n + 1:
            flag = 1
            lap += 1
        # check last char
        if visited and visited[len(visited) - 1][-1] != front[0]: return [flag, lap]
        # check before
        if front not in visited:
            visited.append(front)
            flag += 1
        else: return [flag, lap]

    return [0,0]