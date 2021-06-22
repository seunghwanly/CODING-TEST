from heapq import heappush, heappop


def solution(N, road, K):
    answer = 0
    nodeState = [0 for _ in range(N + 1)]
    graph = [[] for _ in range(N + 1)]
    INF = 100000000001
    # init graph : src, dest, weight
    for r in road:
        src, dest, w = r[0], r[1], r[2]
        if {'dest': dest, 'weight': w} not in graph[src]:
            graph[src].append({'dest': dest, 'weight': w})
        if {'dest': src, 'weight': w} not in graph[dest]:
            graph[dest].append({'dest': src, 'weight': w})
    # set other nodes
    for i in range(1, N + 1):
        if i != 1: nodeState[i] = INF
    
    priorityQueue = []
    heappush(priorityQueue, [1, 0]) # [node, weight]

    while priorityQueue:
        n, w = heappop(priorityQueue)
        if nodeState[n] < w: continue
        for move in graph[n]:
            weighted = w + move['weight']    
            if nodeState[move['dest']] > weighted:
                nodeState[move['dest']] = weighted   
                heappush(priorityQueue, [move['dest'], weighted])
    # check leq K
    for i in range(1, N + 1):
        if nodeState[i] <= K: answer += 1
    return answer


print(
    solution(
        5, [[1, 2, 1], [2, 3, 3], [5, 2, 2], [1, 4, 2], [5, 3, 1], [5, 4, 2]],
        3))
