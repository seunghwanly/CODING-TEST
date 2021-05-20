def solution(n):
    answer = []
    numString = str(n)
    for i in range(len(numString) - 1, -1, -1):
        answer.append(int(numString[i]))
    return answer
    
print(solution(12345))