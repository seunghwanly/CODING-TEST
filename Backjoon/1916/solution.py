import sys
# dijkstra algorithm
from heapq import heappush, heappop
# input
N = int(sys.stdin.readline().rstrip())
M = int(sys.stdin.readline().rstrip())
# N nodes graph
graph = [[] for _ in range(N + 1)]
for i in range(M):
    start, dest, weight = map(int, sys.stdin.readline().split())
    graph[start].append({'dest': dest, 'weight': weight})
# src, dest
beginPoint, endPoint = map(int, sys.stdin.readline().split())

# Bellman Ford's Algorithm
nodeStates= [0] * (N + 1)   # [0] no use
INF = 10000000001
# 1) set other nodes
for i in range(1, N + 1):
    if i != beginPoint: nodeStates[i] = INF
# 2) update node
# start from beginPoint
# using priority queue
priorityQueue = []
# p_queue, [ node, weight ]
heappush(priorityQueue, [beginPoint, 0])
while priorityQueue:
    n, w = heappop(priorityQueue)
    print(priorityQueue)
    if nodeStates[n] < w: continue
    for bus in graph[n]:
        weighted = w + bus['weight']
        if nodeStates[bus['dest']] > weighted:
            nodeStates[bus['dest']] = weighted
            heappush(priorityQueue, [bus['dest'], weighted])

# for bus in graph[beginPoint]:
#     weighted = nodeStates[beginPoint] + bus['weight']
#     if nodeStates[bus['dest']] > weighted: nodeStates[bus['dest']] = weighted
# # update others
# for i in range(1, N+1):
#     if i != beginPoint:
#         for bus in graph[i]:
#             weighted = nodeStates[i] + bus['weight']
#             if nodeStates[bus['dest']] > weighted: nodeStates[bus['dest']] = weighted

print(nodeStates[endPoint])
