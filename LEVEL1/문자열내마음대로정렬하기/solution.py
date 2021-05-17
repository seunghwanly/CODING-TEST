def solution(strings, n):
    strings = sorted(strings, key=(lambda x: x[n]))
    dup = set()
    cnt = {}
    for idx, string in enumerate(strings):
        if string[n] in cnt:
            cnt[string[n]]['end'] = idx
            dup.add(string[n])
        else:
            cnt[string[n]] = {'begin': idx, 'end': -1}
    for c in list(dup):
        if cnt[c]['end'] != -1:
            strings[cnt[c]['begin']:cnt[c]['end'] + 1] = sorted(
                strings[cnt[c]['begin']:cnt[c]['end'] + 1])
    return strings


print(solution(["abce", "abcd", "cdx"], 2))