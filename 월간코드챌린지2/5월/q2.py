import re


def solution(numbers):
    answer = []
    for number in numbers:
        prev = number
        next = number + 1
        while True:
            xor = prev ^ next
            xorStr = re.sub('0', '', bin(xor)[2:])
            if len(xorStr) <= 2:
                answer.append(next)
                break
            else:
                next += 1

    return answer


# print(
#     solution([
#         931931931931931,
#         151510245651221,
#         412135451231334,
#         122589656232065,
#         931565954651616,
#         666165423121324,
#         612315456461232,
#         262615154203212,
#         262612151451155,
#     ]))

print(solution([
    2,
    7,
    15,
    3
]))