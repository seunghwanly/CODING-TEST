function solution(priorities, location) {
    var answer = 0;
    let print = [];

    // init
    priorities.forEach((element, index) => {
        let isLocation = false;
        if (index === location) isLocation = true;
        print.push({ isThatItem: isLocation, item: element });
    });
    let timer = 1;
    while (print.length !== 0) {
        let maxPriority = 0;
        print.forEach((e) => {
            if(maxPriority < e.item) maxPriority = e.item;
        });
        const firstItem = print.shift();
        if(firstItem.isThatItem === true) answer = timer;
        if(maxPriority > firstItem.item) {
            print.push(firstItem);
        }
        else timer++;
    }
    
    return answer;
}

console.log(solution([2, 1, 3, 2], 2));
console.log(solution([1, 1, 9, 1, 1, 1], 0));
