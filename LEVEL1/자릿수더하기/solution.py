def solution(n):
    answer = 0
    numString = str(n)
    for i in numString:
        answer += int(i)
    return answer

