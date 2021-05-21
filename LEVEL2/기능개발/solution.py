def solution(progresses, speeds):
    answer = []
    # get days
    days = []
    for i in range(len(progresses)):
        day = 0
        currProgress = progresses[i]
        while currProgress < 100:
            currProgress += speeds[i]
            day += 1
        days.append(day)
    dayIdx = 1;
    while days:
        cnt = 0
        while days and days[0] <= dayIdx:
            days.pop(0)
            cnt += 1
        if cnt > 0:
            answer.append(cnt)
        dayIdx += 1
    return answer

print(solution([93, 30, 55], [1,30,5]))