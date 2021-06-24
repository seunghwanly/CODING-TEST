def solution(rows, columns, queries):
    answer = []
    # init map
    # rows ↓ columns →
    map = [[j + (i * columns) for j in range(1, columns + 1)] for i in range(rows)]

    # set route -> | V | <- | ^
    dy = [0, 1, 0, -1]
    dx = [1, 0, -1, 0]
    # query [y1, x1, y2, x2], rows : x, column : y
    for query in queries:
        # point(y,x) | query [y1, x1, y2, x2]
        srcPoint = (query[0] - 1, query[1] - 1)
        destPoint = (query[2] - 1, query[3] - 1)

        if rows - 1 == destPoint[1] and columns - 1 == destPoint[
                0] and srcPoint[0] == 0 and srcPoint[1] == 0:
            answer.append(map[query[0] - 1][query[1] - 1])
            continue

        # rotate
        width = destPoint[0] - srcPoint[0] + 1
        height = destPoint[1] - srcPoint[1] + 1
        midWidth = width - 2 if width > 2 else 0
        midHeight = height - 2 if height > 2 else 0
        totalBlock = (width * height) - (midWidth * midHeight)

        currPoint = srcPoint
        currDir = 0
        temp = map[currPoint[0]][currPoint[1]]
        currMin = 1000001

        for i in range(totalBlock):
            nextPoint = (currPoint[0] + dy[currDir],
                         currPoint[1] + dx[currDir])

            # check range
            if nextPoint[1] <= destPoint[1] and nextPoint[0] <= destPoint[
                    0] and nextPoint[1] >= srcPoint[1] and nextPoint[
                        0] >= srcPoint[0]:
                # change item (y,x)
                tempNext = map[nextPoint[0]][nextPoint[1]]
                map[nextPoint[0]][nextPoint[1]] = temp
                temp = tempNext
                # check min
                if currMin > temp: currMin = temp
                # update point
                currPoint = nextPoint
            # max 'x' and min 'y': turn down
            if nextPoint[1] == destPoint[1] and nextPoint[0] == srcPoint[0]:
                currDir = 1
            # max 'x' and max 'y': turn left
            elif nextPoint[1] == destPoint[1] and nextPoint[0] == destPoint[0]:
                currDir = 2
            # min 'x' and max 'y': turn up
            elif nextPoint[1] == srcPoint[1] and nextPoint[0] == destPoint[0]:
                currDir = 3
            # min 'x' and min 'y': end
            elif nextPoint[1] == srcPoint[1] and nextPoint[0] == srcPoint[0]:
                continue

        answer.append(currMin)

    return answer


print(solution(6, 6, [[2, 2, 5, 4], [3, 3, 6, 6], [5, 1, 6, 3]]))
# print(solution(100, 97, [[1, 1, 100, 97]]))
