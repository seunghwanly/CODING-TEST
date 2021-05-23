def solution(s):
    answer = 1001
    if len(s) == 1: return 1
    for i in range(1, len(s)):
        res = ''
        # split by length
        que = [ s[j: j+i] for j in range(0, len(s), i) ]
        cnt = 1
        # que process
        prev = que.pop(0)
        while que:
            front = que.pop(0)
            # print(f'res : {res}, prev : {prev}, front : {front}, cnt : {cnt}')
            if prev == front: 
                cnt += 1
                if len(que) == 0:
                    res += str(cnt) + prev
                    break
            else:
                if cnt > 1:
                    res += str(cnt) + prev
                    cnt = 1
                else: res += prev
            prev = front
            if len(que) == 0: res += prev

        if answer > len(res): answer = len(res)

    return answer

print(solution("a"))