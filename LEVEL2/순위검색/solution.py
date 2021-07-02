def solution(info, query):
    answer = []
    # board init
    board = {}
    score = []

    for name, input in enumerate(info):
        line = input.split()
        board[name] = {
            'lang' : line[0],
            'dept' : line[1],
            'carr' : line[2],
            'food' : line[3]
        }
        score.append((name, int(line[4])))
    score = sorted(score, key=(lambda x : x[1]))
    # queries
    for q in query:
        input = q.split()
        lng, dpt, carr, food, scr = input[0], input[2], input[4], input[6], input[7]
        qCnt = 0
        for s in list(filter(lambda x : x[1] >= int(scr), score)):
            cnt = 0
            if lng == '-' or board[s[0]]['lang'] == lng: cnt += 1
            else: continue
            if dpt == '-' or board[s[0]]['dept'] == dpt: cnt += 1
            else: continue
            if carr == '-' or board[s[0]]['carr'] == carr: cnt += 1
            else: continue
            if food == '-' or board[s[0]]['food'] == food: cnt += 1
            else: continue
            if cnt == 4: qCnt += 1
        answer.append(qCnt)
    
    return answer


print(
    solution([
        "java backend junior pizza 150", "python frontend senior chicken 210",
        "python frontend senior chicken 150", "cpp backend senior pizza 260",
        "java backend junior chicken 80", "python backend senior chicken 50"
    ], [
        "java and backend and junior and pizza 100",
        "python and frontend and senior and chicken 200",
        "cpp and - and senior and pizza 250",
        "- and backend and senior and - 150", "- and - and - and chicken 100",
        "- and - and - and - 150"
    ]))
