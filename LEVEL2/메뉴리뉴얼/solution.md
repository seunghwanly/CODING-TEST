# Solution

각 주문에 대해 `sorted( )`를 통해서 string을 오름차순 list로 변환해주었습니다.
그리고 입력된 `course`에 각 원소만큼 메뉴 갯수를 뽑아야하기 때문에 해당 갯수만큼 가능한 모든 조합을 만들어 저장해줍니다.
이렇게 되면 각 주문에 대해서 모든 경우의 수의 조합이 만들어지게 되고 이를 통해서 Counter를 사용해 빈도수를 확인합니다.

## #1 STEP
``` py
for order in orders:
    orderCombo += combinations(sorted(order), c)
```

1. 입력된 order("ABCFG")를 오름차순으로 정렬
2. 그 중에서 c개 만큼 뽑아 가능한 모든 조합을 생성
3. 입력된 모든 주문("ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH")에서 c개 만큼 뽑아 모든 조합을 orderCombo에 저장

## #2 STEP
```py
mostOrdered = Counter(orderCombo).most_common()
```

입력된 주문으로 만든 모든 조합 중에서 가장 많이 뽑은 것을 선택 (dict 형태)

## #3 STEP
```py
answer += [ k for k, v in mostOrdered if v > 1 and v == mostOrdered[0][1] ]
```
- k는 주문을 뜻하고 v는 주문된 횟수
- 최소 2번 이상 주문되어야하므로 `v > 1` 
- v는 가장 많이 주문된 메뉴 튜플('A', 'C')의 횟수와 같아야 함
- answer에 튜플형태로 저장

