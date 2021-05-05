import sys

testcase = int(sys.stdin.readline().rstrip())

data = [ map(int, sys.stdin.readline().split()) for i in range(testcase)]

for array in data:
    _arr = list(array)
    _arr.sort()
    print(_arr[-3])