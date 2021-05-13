def solution(numbers, hand):
    answer = ''

    pad = [['1', '2', '3'], ['4', '5', '6'], ['7', '8', '9'], ['*', '0', '#']]
    # [y][x]
    leftCurr = [3, 0]
    rightCurr = [3, 2]

    for number in numbers:
        for idx, line in enumerate(pad):
            if str(number) in line:
                res = line.index(str(number))
                if res == 0:
                    answer += 'L'
                    leftCurr = [idx, 0]
                    break
                elif res == 2:
                    answer += 'R'
                    rightCurr = [idx, 2]
                    break
                else:
                    leftDistance = abs(leftCurr[0] - idx) + abs(leftCurr[1] - 1)
                    rightDistace = abs(rightCurr[0] - idx) + abs(rightCurr[1] - 1)
                    if leftDistance == rightDistace:
                        if hand == 'left':
                            answer += 'L'
                            leftCurr = [idx, 1]
                            break
                        else:
                            answer += 'R'
                            rightCurr = [idx, 1]
                            break
                    else:
                        if leftDistance > rightDistace:
                            answer += 'R'
                            rightCurr = [idx, 1]
                            break
                        else:
                            answer += 'L'
                            leftCurr = [idx, 1]
                            break

    return answer


# print(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], "right"))
print(solution([7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2], 'left'))