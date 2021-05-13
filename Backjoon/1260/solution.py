import sys
from collections import deque

def BFS(graph, root):
    visited = []
    queue = deque([root])

    while queue:
        front = queue.popleft()
        if front not in visited:
            visited.append(front)
            if front in graph:
                temp = list(set(graph[front]) - set(visited))
                temp.sort()
                queue += temp
    return ' '.join(str(i) for i in visited)

def DFS(graph, root):
    visited = []
    stack = [root]

    while stack:
        top = stack.pop()
        if top not in visited:
            visited.append(top)
            if top in graph:
                temp = list(set(graph[top]) - set(visited))
                temp.sort(reverse=True)
                stack += temp
    return ' '.join(str(i) for i in visited)

graph = {}
# input
N, M, start = map(int, sys.stdin.readline().split())
for i in range(M):
    src, dest = map(int, sys.stdin.readline().split())
    # duel flex
    if src not in graph: graph[src] = [dest]
    elif dest not in graph[src]: graph[src].append(dest)
    
    if dest not in graph: graph[dest] = [src]
    elif src not in graph[dest]: graph[dest].append(src)

print(DFS(graph, start))
print(BFS(graph, start))

