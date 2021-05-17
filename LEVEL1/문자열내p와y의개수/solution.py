def solution(s):
    s = s.lower()
    p = s.count('p')
    y = s.count('y')
    return True if p == y else False

print(solution("pPpyYY"))