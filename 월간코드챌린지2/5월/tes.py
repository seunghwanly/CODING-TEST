def move(num):
    length = 0;
    front = num
    length += 1
    for i in range(front - 1, 2, -1):
        length += (i-1)
    return length


def solution(numbers):
    answer = []
    for number in numbers:
        prev = number
        next = number + 1
        while True:
            xor = prev ^ next
            xorStr = bin(xor)[2:].count('1')
            if xorStr <= 2:
                answer.append(next)
                break
            else:
                next += xorStr

    return answer


# print(
#     solution([
#         931931931931931, 931931931931931, 931931931931931, 931931931931931,
#         931931931931931, 931931931931931, 931931931931931, 931931931931931,
#         931931931931931, 931931931931931, 931931931931931, 931931931931931,
#         931931931931931, 931931931931931, 931931931931931
#     ]))

print(solution([
    2,
    7,
    15,
    3
]))

# print(move(5))