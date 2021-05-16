def solution(N, stages):
    answer = []
    users = [ {'idx' : i, 'rate' : 0} for i in range(1, N + 1)]
    for i in range(1, N+1):
        fail = 0
        clear = 0
        for user in stages:
            if user == i: fail += 1
            if user >= i: clear += 1
        if clear != 0:
            users[i - 1]['rate'] = fail / clear
    users = sorted(users, key=(lambda x : x['rate']), reverse=True)
    for user in users:
        answer.append(user['idx'])
    return answer

print(solution(5, [2, 1, 2, 6, 2, 4, 3, 3]))