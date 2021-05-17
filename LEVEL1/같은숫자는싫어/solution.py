def solution(arr):
    stack = []
    for num in arr:
        if stack:
            if stack[len(stack) - 1] == num: continue
            else: stack.append(num)
        else: stack.append(num)
    return stack

print(solution([4,4,4,3,3]))