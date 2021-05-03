testcase = int(input())

for turn in range(0,testcase):
    n = int(input())
    n_string = bin(n)[2:]
    n_string = reversed(n_string)
    j = 0
    for i in n_string:
        if i == '1': print(j, end=' ')
        j += 1
