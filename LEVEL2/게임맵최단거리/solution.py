def inRange(y, x, N, M):
    return (0 <= y and y < N) and (0 <= x and x < M)


def isSurrounded(N, M, maps):
    cnt = 0
    dy = [-1, -1, 0]
    dx = [0, -1, -1]

    for i in range(3):
        nextY = N + dy[i]
        nextX = M + dx[i]
        if maps[nextY][nextX] == 0:
            cnt += 1

    return True if cnt == 3 else False


def solution(maps):
    N, M = len(maps), len(maps[0])
    visited = [[False for _ in range(M)] for _ in range(N)]

    # direction
    dy = [0, 0, 1, -1]
    dx = [1, -1, 0, 0]
    
    if isSurrounded(N - 1, M - 1, maps): return -1
    # init
    que = []
    block = 1
    visited[0][0] = True
    que.append((0, 0, block))

    while que:
        front = que.pop(0)
        
        if front[0] == (N - 1) and front[1] == (M - 1):
            return front[2]

        for i in range(4):
            nextY = front[0] + dy[i]
            nextX = front[1] + dx[i]
            if inRange(nextY, nextX, N, M) and visited[nextY][nextX] == False and maps[nextY][nextX] == 1:
                que.append((nextY, nextX, front[2] + 1))
                visited[nextY][nextX] = True

    return -1


print(
    solution([[1, 0, 1, 1, 1], [1, 0, 1, 0, 1], [1, 0, 1, 1, 1],
              [1, 1, 1, 0, 1], [0, 0, 0, 0, 1]]))
