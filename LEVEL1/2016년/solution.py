def solution(a, b):
    days = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT']
    months = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    if a == 1: return days[(b + 4) % 7]
    else:
        daysDiff = 4
        for i in range(a - 1):
            daysDiff += months[i]
        daysDiff += b
        return days[daysDiff % 7]


print(solution(1, 8))