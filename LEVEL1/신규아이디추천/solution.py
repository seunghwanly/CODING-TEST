import re


def solution(new_id):
    answer = ''
    # 정규식 사용
    # to lowercase
    new_id = new_id.lower()
    # remove characters
    new_id = ''.join(re.findall('[a-z0-9-_.]', new_id))
    # ... -> .
    new_id = ''.join(re.sub('[.]{2,}', '.', new_id))
    # check [0] or [len - 1]
    if new_id[0] == '.': new_id = new_id[1:]
    if len(new_id) > 0:
        if new_id[len(new_id) - 1] == '.': new_id = new_id[:-1]
    # check empty string
    if len(new_id) == 0: new_id = 'a'
    # check length
    if len(new_id) >= 16:
        new_id = new_id[:15]
        if new_id[len(new_id) - 1] == '.': new_id = new_id[:-1]
    if len(new_id) <= 2:
        while len(new_id) != 3:
            new_id += new_id[len(new_id) - 1]
    answer = new_id
    return answer


print(solution("...!@BaT#*..y.abcdefghijklm"))
print(solution("z-+.^."))
print(solution("=.="))
print(solution("123_.def"))
print(solution("abcdefghijklmn.p"))
