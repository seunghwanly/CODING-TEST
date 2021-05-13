class Tree {
    constructor(value, passenger) {
        this.value = value;
        this.passenger = passenger;
        this.children = [];
    }

    insert(value, passenger) {
        this.children.push(new Tree(value, passenger));
        return this.children;
    }
}

function solution(n, passenger, train) {

    let map = new Tree(1, passenger[0]);

    for(let i=0; i<train.length; ++i) {
        let dprt = train[i][0];
        let arvl = train[i][1];

        if(map.value === dprt) {
            map.insert(arvl, passenger[arvl - 1]);
        }
        else {
            let index = -1;
            for(let j=0; j < map.children.length; ++j) {
                if(map.children[j].value === dprt) {
                    index = j;
                }
            }
            if(index !== -1) {
                map.children[index].insert(arvl, passenger[arvl - 1]);
            }
        }
    }
    // TODO : DFS 탐색하기
    console.log(JSON.stringify(map));
    

}

console.log(solution(6, [1, 1, 1, 1, 1, 1], [[1, 2], [1, 3], [1, 4], [3, 5], [3, 6]]));
//console.log(solution(4, [2, 1, 2, 2], [[1, 2], [1, 3], [2, 4]]));
//console.log(solution(5, [1, 1, 2, 3, 4], [[1, 2], [1, 3], [1, 4], [1, 5]]));