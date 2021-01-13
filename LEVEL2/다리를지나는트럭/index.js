function solution(bridge_length, weight, truck_weights) {
    var answer = 0;

    let onBridge = {
        weight: 0,
        truckList: [] // {   time : 0, truckWeight : 0 }
    }

    while (true) {
        if (onBridge.truckList.length === 0 && truck_weights.length === 0) return answer;
        answer++;
        if (onBridge.truckList.length != 0) {
            if (onBridge.truckList[0].time + bridge_length === answer) {
                onBridge.weight -= onBridge.truckList[0].truckWeight;
                onBridge.truckList.splice(0, 1);
            }
        }
        if (truck_weights.length != 0) {
            if (weight >= onBridge.weight + truck_weights[0]) {
                let startNewTruckWeight = truck_weights[0];
                truck_weights.splice(0, 1);
                onBridge.truckList.push({ time: answer, truckWeight: startNewTruckWeight });
                onBridge.weight += startNewTruckWeight;
            }
        }
    }

    return answer;
}

console.log(solution(2, 10, [7, 4, 5, 6]));
console.log(solution(100, 100, [10]));
console.log(solution(100, 100, [10, 10, 10, 10, 10, 10, 10, 10, 10, 10]));
console.log(solution(5, 5, [2, 2, 2, 2, 1, 1, 1, 1, 1]));