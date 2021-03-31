function solution(people, limit) {
    let answer = 0;

    people = people.sort((a, b) => a - b);

    let start = 0, end = people.length - 1;

    while (start <= end) {
        if (people[start] + people[end] <= limit) {
            start++;
        }
        end--;
        answer++;
    }

    return answer;
}

console.log(solution([70, 50, 80, 50], 100));
console.log(solution([70, 80, 50], 100));