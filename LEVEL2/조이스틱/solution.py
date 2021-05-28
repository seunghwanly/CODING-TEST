def getDistance(start, dest):
    sInt = ord(start)
    dInt = ord(dest)
    return min(abs(dInt - sInt), abs(dInt - sInt - 26))


def solution(name):
    answer = 0
    index = 0
    while name.count('A') != len(name):
        if name[index] != 'A':
            answer += getDistance('A', name[index])
            if index + 1 < len(name):
                name = name[:index] + 'A' + name[index + 1:]
            else:
                name = name[:index] + 'A'
            if name.count('A') == len(name): break
            # search - left
            rightIndex = index + 1 if index + 1 < len(name) else 0
            leftIndex = index - 1 if index - 1 > 0 else len(name) - 1
            while True:
                if name[leftIndex] != 'A': break
                if leftIndex == 0: leftIndex = len(name) - 1
                else: leftIndex -= 1
            while True:
                if name[rightIndex] != 'A': break
                if rightIndex == len(name) - 1: rightIndex = 0
                else: rightIndex += 1
            # check min
            leftLength = min(abs(index + len(name) - leftIndex), abs(index - leftIndex))
            rightLength = min(abs(index - rightIndex), abs(len(name) - index + rightIndex))
            if leftLength < rightLength:
                answer += abs(leftIndex - index - len(name))
                index = leftIndex
            else:
                answer += abs(rightIndex - index)
                index = rightIndex
    return answer


print(solution("JAN"))
print(solution("JEROEN"))