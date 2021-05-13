import collections


def solution(participant, completion):
    sortp = sorted(participant)
    sortc = sorted(completion)
    for i in range(len(sortp)):
        if i <= len(sortc) - 1:
            if sortp[i] != sortc[i]: return sortp[i]
        if i > len(sortc) - 1: return sortp[len(sortp) - 1]


# print(solution(["leo", "kiki", "eden"], ["eden", "kiki"]))
# print(
#     solution(["mislav", "stanko", "mislav", "ana"],
#              ["stanko", "ana", "mislav"]))


def counter(participant, completion):
    print(collections.Counter(participant))
    print(collections.Counter(completion))


counter(["mislav", "stanko", "mislav", "ana"], ["stanko", "ana", "mislav"])
