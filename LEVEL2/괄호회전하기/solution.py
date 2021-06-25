def solution(s):
    answer = 0
    for i in range(len(s)):
        if i != 0:
            front = s[0]
            s = s[1:] + front

        tempStack = []
        tempString = list(s)
        while tempString:
            top = tempString.pop()
            tempStack.append(top)
            # remove
            if len(tempStack) >= 2:
                topIdx, underTopIdx = len(tempStack) - 1, len(tempStack) - 2
                if (tempStack[underTopIdx] == ')' and tempStack[topIdx]
                        == '(') or (tempStack[underTopIdx] == '}'
                                    and tempStack[topIdx]
                                    == '{') or (tempStack[underTopIdx] == ']'
                                                and tempStack[topIdx] == '['):
                    tempStack = tempStack[:-2]
        if len(tempStack) == 0: answer += 1
    return answer


print(solution("[](){}"))