function solution(bridge_length, weight, truck_weights) {
    var answer = 0;

    let onBridge = {
        weight: 0,
        truckList: [] // {   time : 0, truckWeight : 0 }
        // truckList는 일종의 Queue 역할 : FIFO
    }

    while (true) {
        // 다리위에 지나는 트럭이 없고 출발해야할 트럭도 없을 경우 => answer
        if (onBridge.truckList.length === 0 && truck_weights.length === 0) return answer;
        answer++;   // 시간 계속 흐름
        if (onBridge.truckList.length != 0) {   // 다리 위를 지나는 트럭이 있는 경우
            if (onBridge.truckList[0].time + bridge_length === answer) {    // 출발한 시점 + 다리 길이 == 현재 시간
                // stack에서 제거 : 다리를 지나간 경우
                onBridge.weight -= onBridge.truckList[0].truckWeight;
                onBridge.truckList.splice(0, 1);
            }
        }
        if (truck_weights.length != 0) {    // 출발할 트럭이 남아있는 경우
            if (weight >= onBridge.weight + truck_weights[0]) { // 다리 무게가 버틸 수 있는 지 확인
                let startNewTruckWeight = truck_weights[0]; // top
                truck_weights.splice(0, 1); // pop
                // 다리 위로 트럭을 건너게 시작 ! => 현재 시간을 time에 저장
                onBridge.truckList.push({ time: answer, truckWeight: startNewTruckWeight });
                onBridge.weight += startNewTruckWeight;
            }
        }
    }
}

console.log(solution(2, 10, [7, 4, 5, 6]));
console.log(solution(100, 100, [10]));
console.log(solution(100, 100, [10, 10, 10, 10, 10, 10, 10, 10, 10, 10]));
console.log(solution(5, 5, [2, 2, 2, 2, 1, 1, 1, 1, 1]));