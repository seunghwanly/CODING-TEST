import heapq


def solution(scoville, K):
    answer = 0
    heap = scoville
    heapq.heapify(heap)
    while heap[0] < K:
        if len(heap) == 1 and heap[0] < K: return -1
        first = heapq.heappop(heap)
        second = heapq.heappop(heap)
        newItem = first + (second * 2)
        heapq.heappush(heap, newItem)
        answer += 1
    return answer


print(solution([1, 2, 3, 9, 10, 12], 7))
print(solution([10, 10, 10, 10, 10], 100))
print(solution([0, 0, 3, 9, 10, 12], 7000))