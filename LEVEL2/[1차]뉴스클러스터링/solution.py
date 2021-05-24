import re
from collections import Counter
from functools import reduce


def solution(str1, str2):
    str1 = str1.lower()
    str2 = str2.lower()

    listA = [str1[i:i + 2] for i in range(len(str1) - 1)]
    listB = [str2[i:i + 2] for i in range(len(str2) - 1)]

    flagA = 0
    while flagA < len(listA):
        alphabetCnt = len(list(re.findall('[a-z]', listA[flagA])))
        if alphabetCnt != len(listA[flagA]): listA.pop(flagA)
        else: flagA += 1

    flagB = 0
    while flagB < len(listB):
        alphabetCnt = len(list(re.findall('[a-z]', listB[flagB])))
        if alphabetCnt != len(listB[flagB]): listB.pop(flagB)
        else: flagB += 1

    # dict - Counter
    dictA = Counter(listA)
    dictB = Counter(listB)

    # inter
    intersectionAB = dictA & dictB
    # union
    unionAB = dictA | dictB

    if len(intersectionAB) == 0 and len(unionAB) == 0: return 65536
    elif len(intersectionAB) == 0 and len(unionAB) != 0: return 0
    else: 
        interSum = reduce(lambda x, y: x + y, intersectionAB.values())
        unionSum = reduce(lambda x, y: x + y, unionAB.values())

        return int(interSum / unionSum * 65536)


# print(solution('handshake', 'shake hands'))
# print(solution('aa1+aa2', 'AAAA12'))
# print(solution('E=M*C^2', 'e=m*c^2'))
print(solution('abddd', 'ddefghh'))