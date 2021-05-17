from itertools import combinations
from functools import reduce


def solution(numbers):
    return sorted(list(set([ reduce(lambda acc, cur: item[0] + item[1], item) for item in combinations(numbers, 2) ])))


print(solution([2, 1, 3, 4, 1]))
