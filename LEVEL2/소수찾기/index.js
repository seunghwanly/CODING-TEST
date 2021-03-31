// 소수 판별기
function isPrime(n) {
    if (n <= 1) {   // 1
        return false;
    }
    if (n === 2 || n === 3) {   // 2 or 3
        return true;
    }
    if (n % 2 === 0) {  // 2 times sth
        return false;
    }
    let divisor = 3;
    let limit = Math.sqrt(n);   // 제곱근까지 반복문
    while (limit >= divisor) {  // 제곱근 >= 3
        if (n % divisor === 0) {    // 3,5,7,...의 배수인 경우
            return false;
        }
        divisor += 2;
    }
    return true;
}

function solution(numbers) {
    let elements = numbers.split('');
    console.log(elements);
    let primeNumbers = [];

    const makeCombinations = (arr, str) => {
        // console.log(arr, str, primeNumbers);
        if (arr.length > 0) {
            for (let i = 0; i < arr.length; ++i) {
                const temp = [...arr];
                temp.splice(i, 1);
                makeCombinations(temp, str + arr[i]);
                // console.log(arr, str, primeNumbers, i);
            }
        }
        if (str.length > 0) {
            if (isPrime(+str) && !primeNumbers.includes(+str)) {
                primeNumbers.push(+str);
                // console.log(arr, str, primeNumbers);
            }
        }
    };

    makeCombinations(elements, "");
    return primeNumbers.length;
}

console.log(solution("17"));