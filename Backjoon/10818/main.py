min = 1000000
max = -1000000

N = int(input())
input = list(map(int, input().split()))

for i in input:
    if i > max:
        max = i
    if i < min:
        min = i

print(min, max)