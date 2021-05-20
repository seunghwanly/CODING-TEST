def solution(x):
    divX = sum(map(int, list(str(x))))
    return x % divX == 0

print(solution(10))