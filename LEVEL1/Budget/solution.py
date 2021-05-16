def solution(d, budget):
    answer = 0
    departments = sorted(d)
    currSum = 0
    index = 0
    while currSum + departments[0] <= budget:
        currSum += departments[0]
        del departments[0]
        if not departments: break
    return len(d) - len(departments)

print(solution([1,3,2,5,4], 9))
print(solution([2,2,3,3], 10))