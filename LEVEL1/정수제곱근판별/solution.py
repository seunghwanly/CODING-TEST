def solution(n):
    if str(n ** (1/2))[-2] == '.': return int(((n **(1/2))+1) ** 2)
    else: return -1

print(solution(121))
print(solution(3))