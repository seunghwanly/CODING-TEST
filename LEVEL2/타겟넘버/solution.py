def getAllOperator(set, k, record):
    n = len(set)
    subGetAllOperator(set, "", n, k, record)


def subGetAllOperator(set, prefix, n, k, record):
    if k==0:
        record.append(prefix)
        return
    for i in range(n):
        newPrefix = prefix + set[i]
        subGetAllOperator(set, newPrefix, n, k - 1, record)

def solution(numbers, target):
    answer = 0
    operators = []
    getAllOperator(['+', '-'], len(numbers), operators)


    for i in range(len(operators)):
        res = 0
        for j in range(len(numbers)):
            if operators[i][j] == '-':
                res -= numbers[j]
            else: res += numbers[j]
        if res == target: answer += 1

    return answer

