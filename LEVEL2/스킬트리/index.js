function solution(skill, skill_trees) {
    var answer = 0;
    let skillArray = []; // C, B, D
    let skillIndex = [];

    // push into array
    for (let i = 0; i < skill.length; ++i)
        skillArray.push(skill[i]);

    skill_trees.forEach((element) => {
        for (let j = 0; j < element.length; ++j) {
            if (skillArray.includes(element[j])) skillIndex.push(skillArray.indexOf(element[j]));
        }
        let isInOrder = true;

        skillIndex.forEach((element, index) => {
            if (element != index) isInOrder = false;
        });

        if (isInOrder) answer++;
        skillIndex = [];
    });

    return answer;
}

solution("CBD", ["BACDE", "CBADF", "AECB", "BDA"]);