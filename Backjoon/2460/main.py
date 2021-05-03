maxPassenger = -1
currPassenger = 0
for station in range(0,10):
    getOut, getIn = map(int, input().split())
    currPassenger += getIn - getOut
    if currPassenger > maxPassenger: maxPassenger = currPassenger
print(maxPassenger)