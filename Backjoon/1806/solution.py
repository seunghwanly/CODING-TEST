import sys
# input
N, S = map(int, sys.stdin.readline().split())
numbers = list(map(int, sys.stdin.readline().split()))
# output
answer = N + 1
sum = numbers[0]
# using 2 pointers
i = 0
j = 0
while i <= j and j < N:
    # sum < S -> j++
    if sum < S:
        j += 1
        # list out of index
        if j < N: sum += numbers[j]
        else: break 
    # sum == S -> j++
    elif sum == S:
        #  update answer
        if answer > (j - i + 1): answer = j - i + 1
        j += 1
        if j < N: sum += numbers[j]
        else: break
    # sum > S -> i++
    else:
        if answer > (j - i + 1): answer = j - i + 1
        sum -= numbers[i]
        i += 1
if answer > N: print(0)
else: print(answer)




