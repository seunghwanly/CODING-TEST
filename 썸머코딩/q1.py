def solution(code, day, data):
    answer = []
    dataset = []
    # split data
    for line in data:
        items = line.split()
        # input
        tempPrice = 0
        tempCode = 0
        tempTime = 0
        codeString = items[1][5:]
        dayString = items[2][5:]
        if codeString == code:
            if dayString[:8] == day:
                for item in items:
                    if item.find('price=') != -1:
                        tempPrice = item[6:]
                    if item.find('code=') != -1:
                        tempCode = item[5:]
                    elif item.find('time=') != -1:
                        tempTime = item[5:]
                dataset.append({
                    'price': tempPrice,
                    'code': tempCode,
                    'time': tempTime
                })
    # sort
    dataset = sorted(dataset, key=(lambda x: x['time']))
    # append
    for i in dataset:
        answer.append(int(i['price']))

    return answer


# [110, 95]
print(
    solution("012345", "20190620", [
        "price=80 code=987654 time=2019062113",
        "price=90 code=012345 time=2019062014",
        "price=120 code=987654 time=2019062010",
        "price=110 code=012345 time=2019062009",
        "price=95 code=012345 time=2019062111"
    ]))
