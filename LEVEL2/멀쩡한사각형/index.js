function solution(w, h) {
    var answer = 1;

    if(w > h) {
        let temp = w;
        w = h;
        h = temp;
    }
    
    let sub = 0;

    for (let wi = 1; wi < w + 1; ++wi)
        sub += h === w ? 1 : Math.ceil(h * wi / w) - Math.floor((h * (wi - 1) / w));
        
    answer = w * h - sub;
    return answer;
}

console.log(solution(1000, 27));