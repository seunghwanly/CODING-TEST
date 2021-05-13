def solution(nums):
    setNums = set(nums)
    if len(setNums) > (len(nums) // 2): return len(nums) // 2
    return len(setNums)


# print(solution([3,1,2,3]))
# print(solution([3,3,3,2,2,4]))
print(solution([3, 3, 3, 2, 2, 2]))
