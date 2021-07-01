def solution(bridge_length, weight, truck_weights):
    answer = 0
    # { weight, time }
    wait = truck_weights[:]
    bridge = []
    passed = 0
    currWeight = 0

    while True:
        if passed == len(truck_weights) and len(wait) == 0: return answer
        answer += 1
        # sth needs to be passed
        if bridge:
            if bridge[0]['t'] + bridge_length == answer:
                front = bridge.pop(0)
                currWeight -= front['w']
                passed += 1
        # add new truck
        if wait:
            if currWeight + wait[0] <= weight:
                bridge.append({ 'w' : wait[0], 't' : answer })
                currWeight += wait[0]
                wait.pop(0)


# print(solution(2, 10, [7, 4, 5, 6]))
print(solution(100, 100, [10]))
