def getFactors(num):
    res = []
    for i in range(2, int(num ** (1/2) + 1)):
        if num % i == 0: 
            res.append((i, num // i))
    return res


def solution(brown, yellow):
    total = brown + yellow
    # total = width * height
    # brown = 2 * width + 2 * height - 4
    # width >= height
    list = getFactors(total)
    for h, w in list:
        if w >= h and brown == 2 * w + 2 * h - 4: return [w, h]


# print(solution(10, 2))
print(solution(8, 1))
# print(solution(24, 24))