def solution(t, r):
    answer = []
    passenger = []

    for i in range(len(t)):
        # id, time, rank
        passenger.append({"id": i, "time": t[i], "rank": r[i]})

    passenger = sorted(passenger,
                       key=(lambda x: (-x["time"], -x["rank"], -x["id"])),
                       reverse=True)
    lift = 0
    while passenger:
        # check same time
        candidate = []
        for p in passenger:
            if p["time"] == lift: candidate.append(p)
            else: break
        if candidate:
            # check rank
            candidate = sorted(candidate,
                               key=(lambda x: (x['rank'], x['id'])))
            front = candidate[0]
            # pop
            del passenger[passenger.index(front)]
            answer.append(front["id"])
        # update
        for p in passenger:
            if p["time"] == lift: p["time"] += 1
            else: break
        print(passenger)
        # lift
        lift += 1

    return answer

# print(solution([0, 1, 3, 0], [0, 1, 2, 3]))
# print(solution([7, 6, 8, 1], [0, 1, 2, 3]))
print(solution([0, 0, 0, 1], [0,1,2,0]))
