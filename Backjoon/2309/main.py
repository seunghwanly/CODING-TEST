sum = 0
dwarfs = [int(input()) for _ in range(9)]
for dwarf in dwarfs:
    sum += dwarf

needToLoss = sum - 100
dwarfs.sort()

for i, weightI in enumerate(dwarfs):
    outerBreak = False
    for j, weightJ in enumerate(dwarfs[i + 1:], i):
        if (weightI + weightJ) == needToLoss:
            dwarfs.pop(i)
            dwarfs.pop(j)
            outerBreak = True
            break
    if outerBreak: break

for dwarf in dwarfs: print(dwarf)