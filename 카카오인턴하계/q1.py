numberString = [
    'zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight',
    'nine'
]
numberInt = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

def solution(s):
    answer = 0
    # loop
    for i in range(len(numberString)):
        if numberString[i] in s:
            s = s.replace(numberString[i], str(numberInt[i]))
    answer = int(s)
    return answer

print(solution("one4seveneightsevenseven"))