def solution(n):
    answer = []
    pattern = [ 4, 1, 2]
    while n > 0:
        answer.insert(0, str(pattern[n % 3]))
        if n % 3 == 0: n = n // 3 - 1
        else: n = n // 3
    return ''.join(answer)

print(solution(6))