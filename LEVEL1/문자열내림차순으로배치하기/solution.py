def solution(s):
    return ''.join(sorted(s, key=(lambda x : -ord(x))))

print(solution('Zbcdefg'))