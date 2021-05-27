def isCorrect(string):
    stack = []
    for s in string:
        if s == '(': stack.append(s)
        elif stack: stack.pop()
    return not stack


def seperate(string):
    que = [s for s in string]
    left, right = 0, 0
    u, v = '', ''
    # start que
    while que:
        u += que.pop(0)
        if u[-1] == '(': left += 1
        else: right += 1
        if left == right: break
    v = ''.join(list(que))
    return u, v


def reverse(u):
    return ''.join([')' if s == '(' else '(' for s in u])


def recursive(string):
    # 1
    if string == '': return ''
    # 2
    u, v = seperate(string)
    # 3
    if isCorrect(u): return u + recursive(v)
    else: return '(' + recursive(v) + ')' + reverse(u[1:-1])


def solution(p):
    return p if isCorrect(p) else recursive(p)


# print(solution("()))((()"))
# print(solution("(()())()"))
print(solution(")())()(("))