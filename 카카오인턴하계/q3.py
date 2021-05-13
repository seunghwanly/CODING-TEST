states = []
prevStack = []
currStack = []
removedList = []


def initStates(n):
    global states, currStack, removedList, prevStack
    states = ['O'] * n
    currStack = ['O'] * n
    removedList = []
    prevStack = []


# - : up / + : down / -1000001 : C / 1000001 : Z
def convertCmd(input):
    if input[0] == 'D': return int(input[2])
    elif input[0] == 'U': return int(input[2]) * (-1)
    elif input[0] == 'C': return -1000001
    else: return 1000001


def removeRow(index):
    global states, prevStack, currStack, removedList
    # new index
    movedIndex = 0
    # save
    prevStack = currStack
    removedList.append(index)
    states[index] = 'X'
    # remove
    if index < len(currStack) - 1:
        currStack.pop(index)
        movedIndex = index
    else:
        currStack.pop()
        movedIndex = index - 1
    return movedIndex


def restoreRow(index):
    global states, prevStack, currStack, removedList
    # update index
    movedIndex = 0
    # turn back
    currStack = prevStack
    lastItem = removedList.pop()
    states[lastItem] = 'O'
    # check curr
    if lastItem < index:
        movedIndex = index + 1
    else:
        movedIndex = index
    return movedIndex


def solution(n, k, cmd):
    global states, currStack
    # init States
    initStates(n)
    curr = k
    # loop
    for input in cmd:
        temp = convertCmd(input)
        # move
        if temp != -1000001 and temp != 1000001:
            curr += temp
        # remove
        elif temp == -1000001:
            curr = removeRow(curr)
        # restore
        elif temp == 1000001:
            curr = restoreRow(curr)
        # print(curr, currStack)

    return ''.join(states)


# print(solution(8, 2, ["D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"]))
# print(solution(8, 2, ["D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"]))
# print(solution(4, 3, ["C", "U 1", "C"]))
# print(solution(4, 1, ["C", "D 1", "Z"]))
print(solution(5, 2, ["U 1", "C", "D 2", "C", "U 1", "Z"]))
