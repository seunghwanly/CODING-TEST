import sys

# input H x W
H, W = map(int, sys.stdin.readline().split())
blocks = list(map(int, sys.stdin.readline().split()))
# map[H][W]
map = []
# 1. init block
for height in range(H):
    temp = []
    for width in range(W):
        temp.append(-1)
    map.append(temp)
# 2. set block
for index, value in enumerate(blocks):
    for idx, val in enumerate(range(value)):
        map[H - idx - 1][index] = 1
# 3. sum left and right
for i in range(len(map)):
    prev = -1
    next = -1
    count = 0
    # find `1`
    for j in range(len(map[i])):
        if map[i][j] == 1:
            if count == 0: prev = j
            else: next = j
            count += 1
    # to second `1`
    if next != -1:
        for water in range(prev, next):
            if(map[i][water] != 1): map[i][water] = 2

# sum water
answer = 0
for i in range(len(map)):
    for j in range(len(map[i])):
        if map[i][j] == 2: answer += 1
print(answer)
