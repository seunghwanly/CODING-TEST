def solution(number, k):
    stack = []
    picked = k
    for val in list(number):
        while stack and picked > 0:
            if stack[len(stack) - 1] < val:
                stack.pop()
                picked -= 1
            else: break
        stack.append(val)
    return ''.join(stack[:(len(number) - k)]) if len(stack) > (len(number) - k) else ''.join(stack)

# print(solution("1924", 2))
# print(solution("1231234", 3))
print(solution("11211", 4))