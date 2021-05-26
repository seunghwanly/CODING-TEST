import math
from itertools import permutations


def isPrime(num):
    if num <= 1: return False
    if num <= 3: return True
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0: return False
    return True


def solution(numbers):
    answer = 0
    combos = []
    for i in range(1, len(numbers) + 1):
        combos += permutations(sorted(numbers), i)
    nums = set()
    for combo in combos:
        num = int(''.join(combo))
        nums.add(num)
    for n in nums:
        if isPrime(n): answer += 1
    return answer


print(solution("011"))