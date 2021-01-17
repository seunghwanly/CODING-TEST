//console.log(solution('aaaaaaaaa'));
console.log(solution("aabbaccc"));
console.log(solution("ababcdcdababcdcd"));
console.log(solution("abcabcdede"));
console.log(solution("abcabcabcabcdededededede"));
console.log(solution("xababcdcdababcdcd"));
// console.log(solution('xxxxxxxxxxyyy'));
// console.log(solution('aaaaaaaaaaaaaaaaaaaaaaaa'));
// console.log(solution("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
// console.log(solution('a'));

function solution(s) {
    if (s.length === 1) return 1;
    let answer = Number.MAX_SAFE_INTEGER;
    let pattern = [];
    // 문자열 크기의 절반 수까지 i개 단위로 압축
    for(let patternLength=1; patternLength<= parseInt(s.length/2); patternLength++){
        // 0부터 i개의 문자가 첫 번째 압축 문자
        let compressedString = s.substr(0,patternLength);
        let prefix = 1;
        // j-i부터 i개의 문자와 j부터 i개의 문자가 같으면 prefix 1증가
        // 아니면 compressedString에 그 문자를 숫자와 그대로 붙이기 (1이면 문자만 붙임)
        // 이때 j는 i만큼씩 증가
        for (let j=patternLength; j<= s.length-patternLength; j=j+patternLength){
            if (s.substr(j-patternLength,patternLength) === s.substr(j,patternLength)){
                prefix++;
                if(s.length-j-patternLength<patternLength){
                    compressedString+= prefix;
                }
            }else{
                if (prefix !== 1){
                    compressedString+= prefix;
                    compressedString+=s.substr(j,patternLength);
                }else{
                    compressedString+=s.substr(j,patternLength);
                }
                prefix = 1;
            }
        }
        // 남은 문자열은 압축할 수 없으므로 그대로 붙이기
        compressedString+=s.substr(s.length-1-(s.length % patternLength), (s.length % patternLength));
        pattern.push(compressedString);
    }
    // 제일 압축 잘한 경우 반환
    
    for (let i=0; i< pattern.length; i++){
        if (pattern[i].length < answer){
            answer = pattern[i].length;
        }
    }
    
    return answer;
}