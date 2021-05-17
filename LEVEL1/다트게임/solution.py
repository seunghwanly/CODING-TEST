import re
from functools import reduce


def solution(dartResult):
    numScores = []
    scores = re.findall(r'(\d{1,2})([SDT])+([*#])*', dartResult, flags=0)
    for idx, score in enumerate(scores):
        res = int(score[0])
        # bonus, S = pow(res, 1)
        if score[1] == 'D': res = pow(res, 2)
        elif score[1] == 'T': res = pow(res, 3)
        # option
        if len(score) > 2:
            if score[2] == '*':
                if idx == 0: res *= 2
                else:
                    res *= 2 
                    numScores[idx - 1] *= 2
            elif score[2] == '#':
                res *= (-1)
        # save
        numScores.append(res)
    return reduce(lambda a, b : a + b, numScores)


print(solution("1D2S#10S"))