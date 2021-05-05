# import sys
# # combinations
# from itertools import combinations

# # basic word
# know = ['a', 'n', 'c', 't', 'i']

# # input
# N, K = map(int, sys.stdin.readline().split())
# words = [str(sys.stdin.readline().rstrip()) for i in range(N)]

# # use dictionary
# candidate = {}
# # find most captured
# for word in words:
#     word = word[4:-4]
#     for char in word:
#         if char not in know:
#             if char in candidate:
#                 candidate[char] = candidate[char] + 1
#             else:
#                 candidate[char] = 1
# # sort
# candidate = sorted(candidate.items(), key=(lambda x: x[1]), reverse=True)

# # learn K - know
# # flag = 0
# # for learn in range(K - len(know)):
# #     know.append(candidate[flag][0])
# #     flag += 1
# selected = combinations(candidate, K - len(know))

# answer = 0
# # for loop in selected + know
# for i in selected:
#     temp = []
#     for item in i: temp.append(item[0])
#     knownList = know + temp
#     cnt = 0
#     for word in words:
#         word = word[4:-4]
#         isRead = True
#         for char in word:
#             if char not in knownList:
#                 isRead = False
#                 break
#         if isRead: cnt += 1
#     if answer < cnt: answer = cnt

# # # check words that can be read
# # for word in words:
# #     word = word[4:-4]
# #     isRead = True
# #     for char in word:
# #         if char in know: continue
# #         else:
# #             isRead = False
# #             break
# #     if isRead:
# #         answer += 1
# print(answer)
"""
💡 BIT MASKING을 이용한 조합

예를 들어서 'a'가 0001, 'b'가 0010 인 경우에 'a','b'를 모두 선택한 경우에는 0011이 된다.
[결론] 각 단어에 해당하는 비트마스킹이 포함되어 있다면 읽을 수 있는 경우마다 읽을 수 있는 단어의 수를 알 수 있음
이건 기존 생각과 같은 완전탐색 방법이다.

비트 마스킹이 빠른 이유는 AND 연산과 OR, XOR 연산을 통해 0과 1을 판단해 빠른 비교가 가능하다.
어느 부분 집합이 힌 부분 집합 내 포함되어 있다면 1을 반환할 것이기 때문이다.

* ord(x) : x를 아스키코드로 변환해주는 함수
* words = [] : 입력된 단어들을 저장하는 list
** words[i] |= (1 << ord(x) - ord('a')) :
    모든 단어가 소문자이기 때문에 ASCII 코드에서 제일 첫번째인 a를 기준으로 얼마나 떨어져 있는지 계산을 한다
    그 다음에는 그만큼 1을 left-shift 해준다.
    예) antarbuyuoctica
    anta + rbuyuoc + tica 이기 때문에 rbuyuoc에 해당하는 1들이 words[i]에 저장된다.
    0000 0001 0001 0010 0100 0000 0000 0110
           zy xwvu tsrq ponm lkji hgfe dcba

'a','c','t','i','n'을 제외한 나머지 알퍼벳 중에서 K - 5(know, 알고있는 알파벳) 만큼의 조합이 필요하다.
가능한 조합 내에서 반복문을 통해 진행
1) 알고 있는 리스트(know)에서 먼저 검색 → OR 연산
2) 조합된 후보 리스트(candidates → selected) → OR 연산
3) 입력된 단어들과의 AND 연산 → 결과가 단어로 같은 경우 → 읽을 수 있는 단어
"""

import sys
import itertools

# basic alphabet
base = ['a', 'c', 't', 'i', 'n']
# candidate
candidate = [
    'b', 'd', 'e', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
    's', 'u', 'v', 'w', 'x', 'y', 'z'
]

# input
N, K = map(int, sys.stdin.readline().split())
words = [0] * N
for i in range(N):
    input = sys.stdin.readline().rstrip()
    for c in input:
        words[i] |= (1 << (ord(c) - ord('a')))

if K < 5: print(0)
else:
    answer = 0
    # combination
    combination = list(itertools.combinations(candidate, K - len(base)))
    for item in combination:
        # OR operand result
        orResult = 0
        # count for get max
        cnt = 0
        # 1) OR operand with base
        for char in base:
            orResult |= (1 << (ord(char) - ord('a')))
        # 2) OR operand with candidate
        for char in item:
            orResult |= (1 << (ord(char) - ord('a')))
        # 3) compare with words
        for word in words:
            # AND operand with words
            if orResult & word == word: cnt += 1
        # check max
        if answer < cnt: answer = cnt
    print(answer)