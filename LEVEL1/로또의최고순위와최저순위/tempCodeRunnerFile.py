def solution(lottos, win_nums):
    # candidates
    zeroCnt = 0
    for lotto in lottos:
        if lotto == 0: zeroCnt += 1
    # copy
    numStack = win_nums
    for i in range(len(win_nums)):
        if lottos[i] in numStack:
            numStack.pop(numStack.index(lottos[i]))
    minPrice = 6 if len(numStack) + 1 > 6 else len(numStack) + 1
    maxPrice = 6 if len(numStack) - zeroCnt + 1 > 6 else len(
        numStack) - zeroCnt + 1

    return [maxPrice, minPrice