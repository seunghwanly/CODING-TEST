function solution(nums) {
    let answer = 0;
    let arrays = [];
    // combination
    const combinations = (nums, num, arr = []) => {
        //3개를 선택한다는가정에 3개가 선택 됐다면 출력
        if (num === 3) arrays.push([...arr]);
        else {
            for (let i = 0; i < nums.length; i++) {
                arr.push(nums[i]);
                combinations(nums.slice(i + 1), num + 1, arr);
                arr.pop();
            }
        }
    };
    // prime
    const isPrime = (num) => {
        for (let i = 2; i < num; i++)
            if (num % i === 0) return false;
        return num > 1;
    }
    // get combination
    combinations(nums, 0);

    arrays.forEach(subArr => {
        let sum = subArr.reduce((a,b) => a+b);
        if(isPrime(sum)) answer++;
    });

    return answer;
}
console.log(solution([1, 2, 3, 4]));
console.log(solution([1, 2, 7, 6, 4]));