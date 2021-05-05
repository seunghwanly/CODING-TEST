import sys

leftSmall = '('
rightSmall = ')'
leftBig = '['
rightBig = ']'

# to stack
stack = list(map(str, sys.stdin.readline().rstrip()))
stack.reverse()

smallCount = 0
bigCount = 0

temp = []
while stack:
    top = stack.pop()
    temp.append(top)
    # print("top :",top,"temp :", temp)
    # save status
    prevSmall, prevBig = smallCount, bigCount
    # status change
    if top == leftSmall: smallCount += 1
    elif top == rightSmall: smallCount -= 1
    elif top == leftBig: bigCount += 1
    elif top == rightBig: bigCount -= 1
    # is Changed?
    if prevSmall > smallCount:
        # small closed !
        # check temp list
        rightIndex = len(temp) - 1
        leftIndex = -1
        for itemIndex in range(len(temp) - 1, -1, -1):
            if temp[itemIndex] == leftSmall:
                leftIndex = itemIndex
                break
        if abs(rightIndex - leftIndex) == 1:
            temp = temp[:-2]
            temp.append(2)
        else:
            midValue = temp[rightIndex - 1]
            temp = temp[:-3]
            temp.append(midValue * 2)
    if prevBig > bigCount:
        # big closed !
        # check temp list
        rightIndex = len(temp) - 1
        leftIndex = -1
        for itemIndex in range(len(temp) - 1, -1, -1):
            if temp[itemIndex] == leftBig:
                leftIndex = itemIndex
                break
        if abs(rightIndex - leftIndex) == 1:
            temp = temp[:-2]
            temp.append(3)
        else:
            midValue = temp[rightIndex - 1]
            temp = temp[:-3]
            temp.append(midValue * 3)
    # print(smallCount, bigCount, temp)
    #  check temp
    if len(temp) - 2 > 0:
        lastElement = temp[len(temp) - 1]
        secondElement = temp[len(temp) - 2]
        if type(lastElement) is int and type(secondElement) is int:
            sumElement = lastElement + secondElement
            temp = temp[:-2]  # remove
            temp.append(sumElement)

sum = 0
notInt = False
for i in temp:
    if type(i) is not int:
        notInt = True
        break
    sum += i
if notInt or smallCount < 0 or bigCount < 0: print(0)
else: print(sum)
