import re


def solution(s):
    find = re.findall(r'[0-9]', s)
    return len(s) == len(find) and len(s) == 4 or len(s) == 6