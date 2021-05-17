def solution(s, n):
    answer = ''
    for char in s:
        if char == " ": answer += " "
        else:
            if (ord(char) + n > 90 and ord(char) >= 65
                    and ord(char) <= 90) or (ord(char) + n > 122
                                             and ord(char) >= 97
                                             and ord(char) <= 122):
                answer += chr(ord(char) + n - 26)
            else:
                answer += chr(ord(char) + n)
    return answer


print(solution('AB', 1))
print(solution('z', 1))
print(solution('Z', 10))
print(solution(' aBZ', 4))
