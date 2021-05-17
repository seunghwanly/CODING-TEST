def solution(n, arr1, arr2):
    answer = []
    for a, b in zip(arr1, arr2):
        num = a | b
        toBin = bin(num)[2:]
        if len(toBin) < n: toBin = '0' * (n - len(toBin)) + toBin
        temp = []
        for c in toBin:
            if c == '1': temp.append('#')
            else: temp.append(' ')
        answer.append(''.join(temp))

    return answer


print(solution(5, [9, 20, 28, 18, 11], [30, 1, 21, 17, 28]))