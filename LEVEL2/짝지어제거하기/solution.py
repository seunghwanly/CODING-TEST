def solution(s):
    stack = []
    for i in s:
        if len(stack) > 0:
            if stack[len(stack) - 1] == i:
                stack.pop()
                continue
        stack.append(i)
    return 1 if len(stack) == 0 else 0

print(solution("baabaa"))