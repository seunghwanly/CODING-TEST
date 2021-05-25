from collections import Counter
from itertools import combinations


def solution(orders, course):
    answer = []

    for c in course:
        orderCombo = []
        for order in orders:
            orderCombo += combinations(sorted(order), c)

        mostOrdered = Counter(orderCombo).most_common()
        answer += [ k for k, v in mostOrdered if v > 1 and v == mostOrdered[0][1] ]
    return [''.join(v) for v in sorted(answer)]


print(solution(["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"], [2, 3, 4]))
