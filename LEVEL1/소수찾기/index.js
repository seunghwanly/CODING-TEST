function solution(n) {
    var answer = 0;

    var array = [];
    array[0] = -1;
    array[1] = -1;

    for(var i=2; i<=n; ++i) array[i] = i;

    for(var i = 2; i<=n; ++i) {
        for(var j= 2*i; j<=n; j += i) array[j] = -1;
    }

    array.forEach(v => {
        if(v !== -1) answer++;
    });
    
    return answer;
}

console.log("answer "+ solution(45650));