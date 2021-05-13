function solution(gift_cards, wants) {
    var answer = 0;

    let have = [];
    for (let i = 0; i < gift_cards.length; ++i) {
        have.push(
            {
                card: gift_cards[i],
                want: wants[i]
            }
        );
    }

    let match = 0;

    // check for match
    have.forEach((element, index) => {
        if (element.card === element.want) {
            match++;
            have.splice(index, 1);
        }
    });

    // change
    have.forEach((element, index) => {
        if (element.card !== element.want) {
            for (let j = index + 1; j < have.length; ++j) {
                if (element.want === have[j].card) {
                    // switch
                    let temp = element.card;
                    element.card = have[j].card;
                    have[j].card = temp;

                    match++;
                    break;
                }
            }
        } else {
            match++;
        }
    })

    answer = gift_cards.length - match;

    return answer;
}

console.log(solution([4, 5, 3, 2, 1], [2, 4, 4, 5, 1]));
console.log(solution([5, 4, 5, 4, 5], [1, 2, 3, 5, 4]));