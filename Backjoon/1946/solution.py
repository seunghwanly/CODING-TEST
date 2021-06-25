import sys

T = int(sys.stdin.readline().rstrip())

for index in range(T):
    N = int(sys.stdin.readline().rstrip())
    # applicatns
    applicants = [[] for _ in range(T)] 
    for i in range(N):
        doc, talk = map(int, sys.stdin.readline().split())
        applicants[index].append({'applicant': i, 'doc': doc, 'talk': talk})
    rank = sorted(applicants[index], key=lambda x: (x['doc']))
    answer = 1
    minRank = rank[0]
    for i in range(1, N):
        if (rank[i]['talk'] < minRank['talk']):
            minRank = rank[i]
            answer += 1
    print(answer)