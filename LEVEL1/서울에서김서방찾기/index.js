function solution(seoul) {
    var answer = '';

    seoul.forEach((value, index) => {
        if(value == "Kim") answer = "김서방은 " + index + "에 있다";
    });
    return answer;
}

solution(["Jane", "Kim"]);