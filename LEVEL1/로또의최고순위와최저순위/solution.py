def solution(lottos, win_nums):
    # candidates
    zeroCnt = lottos.count(0)
    # copy
    numStack = win_nums
    for i in range(len(win_nums)):
        if lottos[i] in numStack:
            numStack.pop(numStack.index(lottos[i]))
    minPrice = 6 if len(numStack) + 1 > 6 else len(numStack) + 1
    maxPrice = 6 if len(numStack) - zeroCnt + 1 > 6 else len(numStack) - zeroCnt + 1

    return [maxPrice, minPrice]


print(solution([44, 1, 0, 0, 31, 25], [31, 10, 45, 1, 6, 19]))
print(solution([32, 18, 44, 12, 16, 11], [31, 10, 45, 1, 6, 19]))