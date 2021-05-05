import sys

# input
N = int(sys.stdin.readline().rstrip())
numbers = list(map(int, sys.stdin.readline().split()))
operators = list(map(int, sys.stdin.readline().split()))

MIN = 1000000000
MAX = -1000000000


# 완전탐색
def search(picked, result):
    global MIN, MAX, numbers, operators
    if picked == N:
        if MIN > result:
            MIN = result
        if MAX < result:
            MAX = result
    else:
        for i in range(4):
            if operators[i] > 0:
                operators[i] -= 1
                if i == 0: search(picked + 1, result + numbers[picked])
                elif i == 1: search(picked + 1, result - numbers[picked])
                elif i == 2: search(picked + 1, result * numbers[picked])
                else: search(picked + 1, int(result / numbers[picked]))
                operators[i] += 1

search(1, numbers[0])

print(MAX)
print(MIN)
