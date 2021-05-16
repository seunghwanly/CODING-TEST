def solution(n):
    answer = 0
    res = []
    while n > 0:
        res.insert(0, n % 3)
        n = n // 3
    power = 0
    for i in res:
        answer += i * (3**power)
        power += 1
    return answer


print(solution(45))