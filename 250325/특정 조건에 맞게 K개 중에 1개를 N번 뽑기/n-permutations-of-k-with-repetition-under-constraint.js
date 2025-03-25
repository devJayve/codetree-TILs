const fs = require("fs");
const input = fs.readFileSync(0).toString().trim().split('\n');

const [k, n] = input[0].split(' ').map(Number);

// 1이상 k이하의 수 -> N번 뽑기
// 같은 수가 연속해서 3번 이상 나오는 경우 제외할 것

let number = [];

function makeNumber(cnt) {
    if (cnt === n) {
        console.log(number.join(' '));
        return;
    }

    for (let i = 1; i <= k; i++) {
        if (number.length >= 2 && number[number.length - 1] === i && number[number.length - 2] === i) continue;
        number.push(i);
        makeNumber(cnt + 1);
        number.pop();
    }
}

makeNumber(0);