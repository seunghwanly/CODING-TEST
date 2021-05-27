from functools import cmp_to_key


def compareTwoElement(x, y):
    temp1 = x+y
    temp2 = y+x
    return (int(temp1) < int(temp2)) - (int(temp2) < int(temp1))


def solution(numbers):
    n = [str(i) for i in numbers]
    n = sorted(n, key=cmp_to_key(compareTwoElement))
    
    return str(int(''.join(n)))


print(solution([6, 10, 2]))
print(solution([3, 30, 34, 5, 9]))