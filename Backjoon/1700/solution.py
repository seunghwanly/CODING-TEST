import sys

# input
N, K = map(int, sys.stdin.readline().split())
names = list(map(int, sys.stdin.readline().split()))

# output
plugs = []
# set plugs
for i in range(K):
    if len(plugs) == N: break
    if names[i] not in plugs:
        plugs.append(names[i])
answer = 0
# search all names
for i in range(N, K):
    # already plugged in
    if names[i] in plugs: continue
    # not plugged in && no space for plug
    # save in list
    temp = []
    # search in plugs, sth to plug-out
    for j in range(N):
        if plugs[j] in names[i:]: 
            nextIndex = names[i:].index(plugs[j])
        else:
            # not found -> more than max value(100)
            nextIndex = 101
        temp.append(nextIndex)
    # plug-out the bigggest item in temp
    plugOutIndex = temp.index(max(temp))
    # pop from plugs
    plugs.pop(plugOutIndex)
    # plug-in
    plugs.append(names[i])
    # increase count
    answer += 1
print(answer)