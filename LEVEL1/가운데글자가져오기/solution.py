def solution(s):
    if len(s) % 2 != 0: return s[len(s) // 2]
    else: return s[len(s) // 2:len(s) // 2 + 2]
