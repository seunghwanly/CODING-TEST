def getD(num):
    numbers = []
    for i in range(1, num + 1):
        if num % i == 0: numbers.append(i)
    return len(numbers)

def solution(left, right):
    answer = 0
    for i in range(left, right + 1):
        res = getD(i)
        if res % 2 == 0: answer += i
        else: answer -= i
    return answer
