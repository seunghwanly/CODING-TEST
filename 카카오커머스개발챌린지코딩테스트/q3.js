function solution(next_student) {
    var answer = 0;

    let students = [];

    let cnt = [];

    // init
    for (let i = 0; i < next_student.length; ++i) {
        students[i] = {
            number: i + 1,
            to: next_student[i],
            from: -1
        }
        cnt[i] = {
            student: i + 1,
            cnt: 0
        };
    }

    students.forEach(s => {
        if (students[s.to - 1] !== undefined) {
            students[s.to - 1].from = s.number;
        }
    })

    students.forEach(s => {
        let to = s.to;
        let sender = s.number;
        let route = [];
        while (to !== 0) {
            if (route.find(e => e === sender)) {
                route = [];
                break;
            }
            if (students[sender - 1].to !== 0) {
                route.push(sender);
                cnt[s.number - 1].cnt += 1;
                sender = to;
                to = students[sender - 1].to;
            }
        }
    })
    
    cnt.sort(
        function (a, b) {
            if (a.cnt > b.cnt) {
                return 1;
            }
            if (a.cnt < b.cnt) {
                return -1;
            }
            return 0;
        }
    );
    answer = cnt[next_student.length-1].student;

    return answer;
}

console.log(solution([5, 9, 13, 1, 0, 0, 11, 1, 7, 12, 9, 9, 2]));
// console.log(solution([6, 10, 8, 5, 8, 10, 5, 1, 6, 7]));