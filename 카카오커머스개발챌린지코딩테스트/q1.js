function solution(n, record) {
    var answer = [];

    let server = [
        [],
        [],
        [],
        [],
        [],
        [],
        [],
        [],
        [],
        []
    ]; // server : 1 ~ 9

    record.forEach(element => {
        let indexAndNickname = element.split(' ');
        let serverIdx = indexAndNickname[0];
        let nickname = indexAndNickname[1];

        if (server[serverIdx - 1].find((e) => e === nickname) === undefined) {
            if (server[serverIdx - 1].length === 5)
                server[serverIdx - 1].shift();
            server[serverIdx - 1].push(nickname);
        }
    });

    for(let i=0; i<9; ++i) {
        server[i].forEach(e => {
            if(e != '') answer.push(e);
        });        
    }

    return answer;
}

console.log(solution(1, ["1 fracta", "1 sina", "1 hana", "1 robel", "1 abc", "1 sina", "1 lynn"]));
console.log(solution(4, ["1 a", "1 b", "1 abc", "3 b", "3 a", "1 abcd", "1 abc", "1 aaa", "1 a", "1 z", "1 q", "3 k", "3 q", "3 z", "3 m", "3 b"]));