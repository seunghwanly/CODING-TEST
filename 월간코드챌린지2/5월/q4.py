from queue import Queue


def solution(values, edges, queries):
    answer = []
    nodevalues = [i for i in values]
    parent = [-1 for i in range(len(values) + 1)]
    # set map
    map = [[] for i in range(len(values) + 1)]
    for edge in edges:
        src = edge[0]
        dest = edge[1]
        # find parent
        parent[dest] = src
        # set child
        map[src].append(dest)
    #  queries
    for query in queries:
        # check command
        if query[1] == -1:
            # sum all sub node
            que = []
            que.append(query[0])
            sum = 0
            while que:
                front = que.pop(0)
                sum += nodevalues[front - 1]
                if len(map[front]) > 0:
                    for child in map[front]:
                        que.append(child)
            answer.append(sum)
        else:
            # delete u and copy
            # 1. delete
            values[query[0] - 1] = 0
            # 2. find parent and paste
            stack = []
            stack.append(parent[query[0]])
            nodevalues[query[0] - 1] = nodevalues[stack[-1] - 1]
            while stack:
                top = stack.pop()
                nodevalues[top - 1] = nodevalues[parent[top] - 1]
                if len(stack) > 0:
                    stack.append(parent[stack[-1]])
            # 3. set root to w
            nodevalues[0] = query[1]

    return answer


print(
    solution([1, 10, 100, 1000, 10000], [[1, 2], [1, 3], [2, 4], [2, 5]],
             [[1, -1], [2, -1], [3, -1], [4, -1], [5, -1], [4, 1000], [1, -1],
              [2, -1], [3, -1], [4, -1], [5, -1], [2, 1], [1, -1], [2, -1],
              [3, -1], [4, -1], [5, -1]]))
