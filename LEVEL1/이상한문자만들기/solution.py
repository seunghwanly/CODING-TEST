def solution(s):
    answer = ''
    flag = 0
    for i in range(len(s)):
        if s[i] == ' ': 
            flag = 0
            answer += s[i]
            continue
        if flag % 2 == 0: answer += s[i].upper()
        else: answer += s[i].lower()
        flag += 1
    return answer

print(solution("try hello world"))