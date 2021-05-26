from operator import itemgetter


def solution(priorities, location):
    answer = 1
    que = []
    # init que
    for index, p in enumerate(priorities):
        que.append((index, p))
    # while loop
    while que:
        front = que.pop(0)
        # sort
        if len(que) > 0:
            if front[1] < max(que, key=itemgetter(1))[1]:
                que.append(front)
                continue
        if front[0] == location: break
        else: answer += 1
    return answer


print(solution([2, 1, 3, 2], 2))
print(solution([1, 1, 9, 1, 1, 1], 1))