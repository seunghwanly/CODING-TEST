def solution(record):
    stack = []
    nickname = {}

    for log in record:
        cmd = log.split()
        if cmd[0] == "Enter":
            nickname[cmd[1]] = cmd[2]
            stack.append(f'{cmd[1]}$님이 들어왔습니다.')
        elif cmd[0] == "Leave":
            stack.append(f'{cmd[1]}$님이 나갔습니다.')
        else:
            nickname[cmd[1]] = cmd[2]

    for i, s in enumerate(stack):
        idIdx = s.index('$')
        if s[:idIdx] in nickname:
            stack[i] = nickname[s[:idIdx]] + s[idIdx + 1:]
    
    return stack


print(
    solution([
        "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234",
        "Enter uid1234 Prodo", "Change uid4567 Ryan"
    ]))
