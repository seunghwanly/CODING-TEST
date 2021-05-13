map = []
visited = [[False] * 5 for _ in range(5)]

def getDistance(y2, x2, y1, x1):
    return abs(y2 - y1) + abs(x2 - x1)


def inRange(y, x):
    return True if y >= 0 and y <= 4 and x >= 0 and x <= 4 else False


def nearBy(y, x):
    global map, visited
    p = []
    for i in range((y + 1) + 2):
        for j in range((x + 1) + 2):
            nextY = y + i
            nextX = x + j
            if inRange(nextY, nextX):
                if map[nextY][nextX] == 'P' and visited[nextY][nextX] == False:
                    visited[nextY][nextX] = True
                    p.append((nextY, nextX))
    return p


def checkPath(y2, x2, y1, x1):
    # print(f'[{y2}, {x2}] -> [{y1},{x1}]')
    # (y2, x2) -> (y1, x1)
    global map, visited

    hy = y1 - y2
    hx = x1 - x2
    # in one line

    checkCnt = abs(hy) + abs(hx)
    checked = 0

    if y2 == y1: checkCnt -= 1
    if x2 == x1: checkCnt -= 1
    # y
    for i in range(abs(hy)):
        # check +, -
        if hy < 0: movedY = y2 + (i + 1) * (-1)
        else: movedY = y2 + (i + 1)
        # check in map
        if map[movedY][x2] == 'X': checked += 1
        if map[movedY][x2] == 'O': return False
    # x
    for i in range(abs(hx)):
        # check +,-
        if hx < 0: movedX = x2 + (i + 1) * (-1)
        else: movedX = x2 + (i + 1)
        # check map
        if map[y2][movedX] == 'X': checked += 1
        if map[y2][movedX] == 'O': return False

    if checked == checkCnt: return True
    else: return False


def solution(places):
    global map, visited
    answer = []

    for place in places:
        result = 1
        map.clear()
        map = place
        pNumber = 0
        # map
        for i in range(5):
            for j in range(5):
                if map[i][j] == 'P':
                    pNumber += 1
                    ps = nearBy(i, j)
                    pResult = True
                    for p in ps:
                        # p[0] : y , p[1] : x
                        if p[0] != i or p[1] != j:
                            if getDistance(p[0], p[1], i, j) > 2: continue
                            elif getDistance(p[0], p[1], i, j) == 1:
                                pResult = False
                                break
                            else:
                                if checkPath(i, j, p[0], p[1]): continue
                                else:
                                    pResult = False
                                    break
                    if pResult == False:
                        result = 0
        if result == 0: 
            if pNumber == 0:
                answer.append(1)
            else:
                answer.append(0)
        else: answer.append(1)

    return answer


print(
    solution([["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"],
              ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"],
              ["PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"],
              ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"],
              ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]))
# print(solution([["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"]]))
# print(solution([["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"]]))
# print(solution([["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"]]))
# print(solution([["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]))