import re
from itertools import permutations


def calculate(prev, next, op):
    if op == '+': return prev + next
    elif op == '-': return prev - next
    else: return prev * next


def getNodes(string):
    numbers = re.findall(r'(\d+)', string)
    operators = re.findall(r'[+*-]', string)
    return numbers, operators


def convertQueue(numbers, operators):
    que = []
    for i in range(len(numbers)):
        que.append(numbers[i])
        if i < len(operators):
            que.append(operators[i])
    return que


def solution(expression):
    answer = 0
    nums, ops = getNodes(expression)
    # operators priority
    operators = set(ops)
    combos = permutations(operators, len(operators))
    # make queue
    que = convertQueue(nums, ops)
    for combo in combos:
        # search
        tempOP = list(combo).copy()
        tempQue = que.copy()
        while tempOP:
            front = tempOP.pop(0)
            i = 0
            while i + 1 < len(tempQue):
                if tempQue[i + 1] == front:
                    prev = tempQue.pop(i)
                    curr = tempQue.pop(i)
                    next = tempQue.pop(i)
                    now = str(calculate(int(prev), int(next), curr))
                    tempQue.insert(i, now)
                else:
                    i += 1
        if len(tempQue) == 1:
            res = abs(int(tempQue[0]))
            if res > answer: answer = res
    return answer


print(solution("200-300-500-600*40+500+500"))
# print(solution("100-200*300-500+20"))
# print(solution("50*6-3*2"))
