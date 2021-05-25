def solution(s):
    answer = []
    sque = s[1:-1]
    stack = []
    temp = set()
    tempInt = ''
    for i in range(len(sque)):
        if sque[i] == '{': 
            temp = []
        elif sque[i] == '}':
            if len(tempInt) > 0 and i == len(sque) - 1: 
                temp.append(int(tempInt))
            stack.append(temp)
        elif sque[i] == ',':
            temp.append(int(tempInt))
            tempInt = ''
        else:
            tempInt += sque[i]
            
    stack = sorted(stack, key=(lambda x: len(x)))

    while stack:
        front = stack.pop(0)
        while front:
            element = front.pop(0)
            if element not in answer:
                answer.append(element)
    return answer


# print(solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"))
# print(solution("{{1,2,3},{2,1},{1,2,4,3},{2}}"))
print(solution("{{20,111},{111}}"))