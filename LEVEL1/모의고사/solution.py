def solution(answers): 
    answer = []   
    firstPattern = [1,2,3,4,5]
    secondPattern = [2,1,2,3,2,4,2,5]
    thirdPattern = [3,3,1,1,2,2,4,4,5,5]
    
    cnt = [0, 0, 0]
    flag = [0, 0, 0]
    
    for i in range(len(answers)):
        if answers[i] == firstPattern[flag[0]] : cnt[0] += 1
        if answers[i] == secondPattern[flag[1]] : cnt[1] += 1
        if answers[i] == thirdPattern[flag[2]] : cnt[2] += 1
        
        for j in range(3):
            flag[j] += 1
        
        flag[0] %= len(firstPattern)
        flag[1] %= len(secondPattern)
        flag[2] %= len(thirdPattern)        
    
    isSame = all(i == cnt[0] for i in cnt)
    if isSame: return [1,2,3]

    maxCnt = max(cnt)
    for i in range(3):
        if maxCnt == cnt[i]:
            answer.append((i+1))
        
    return answer

print(solution([1,2,3,4,5]))
print(solution([1,3,2,4,2]))