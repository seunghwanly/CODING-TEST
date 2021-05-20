def solution(arr):
    if len(arr) > 1:
        item = min(arr)
        del arr[arr.index(item)]
        return arr
    else: return [-1]

print(solution([4,3,2,1]))
print(solution([4]))