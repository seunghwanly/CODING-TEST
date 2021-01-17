function solution(s) {
    var answer = s.length;

    let pattern = [];
    let patternLength = 1;

    while (patternLength < s.length) {
        for (let i = 0; i < s.length; i += patternLength) {
            let tempString = "";
            let maxIndex = i + patternLength > s.length ? s.length : i + patternLength;
            for (let j = i; j < maxIndex; ++j) {
                tempString += s[j];
            }
            pattern.push(tempString);
        }
        // check pattern
        let prefix = 1;
        let compressedString = "";
        for (let i = 1; i < pattern.length; ++i) {
            //console.log(i - 1 + " > " + pattern[i - 1] + "\t" + i + " > " + pattern[i] + "\t" + compressedString)
            // a, a, b, b
            if (pattern[i - 1] === pattern[i]) {
                // 첫 번째 or 전 문자가 현재랑 다른 느낌
                // console.log(compressedString.substr(compressedString.length - patternLength, patternLength))
                if (compressedString.substr(compressedString.length - patternLength, patternLength) !== pattern[i]) {
                    prefix = 2;
                } else { // 전 문자랑 같은 문자
                    prefix += 1;
                    if (Number.isInteger(parseInt(compressedString[compressedString.length - patternLength - 1]))) {
                        let k = 1;
                        if(Number.isInteger(parseInt(compressedString[compressedString.length - patternLength - 2]))) {
                            // 두자리 일 수도 있음
                            while(Number.isInteger(parseInt(compressedString[compressedString.length - patternLength - k]))) k++;
                        }
                        compressedString = compressedString.slice(0, -(patternLength + k));
                    }
                    else {
                        // 2abcabcdedede 에서 -1 을 해서 2abcabcdeded 가 되버림..
                        if (compressedString.substr(compressedString.length - patternLength, patternLength) === pattern[i])
                            compressedString = compressedString.slice(0, -(patternLength));
                        else
                            compressedString = compressedString.slice(0, -1);
                    }
                }
                compressedString += prefix.toString() + pattern[i];
            } else {
                if (compressedString === '') compressedString += pattern[i - 1];
                prefix = 1;
                compressedString += pattern[i];
            }
        } 
        //console.log("\n", patternLength, compressedString, compressedString.length, '\n');

        if (answer > compressedString.length) answer = compressedString.length;

        pattern = [];

        patternLength++;
    }

    return answer;
}

//console.log(solution("aabbaccc"));
// console.log(solution("ababcdcdababcdcd"));
// console.log(solution("abcabcdede"));
//console.log(solution("abcabcabcabcdededededede"));
// console.log(solution("xababcdcdababcdcd"));
// console.log(solution('xxxxxxxxxxyyy'));
//console.log(solution('aaaaaaaaaaaaaaaaaaaaaaaa'));
//console.log(solution("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
console.log(solution('a'));