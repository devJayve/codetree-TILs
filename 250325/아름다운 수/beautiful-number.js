const fs = require("fs");
const input = fs.readFileSync(0).toString().trim().split('\n');

const n = Number(input[0]);

// 1) 1이상 4이하 정수
// 2) 해당 숫자만큼 연달아 등장

let numbers = [];
let beautifulCnt = 0;

function checkIsBeautiful() {
    if (numbers.length === 1) {
        return numbers[0] === 1;
    }
    for (let i = 0; i < numbers.length; i++) {
        if (i + numbers[i] > numbers.length) return false;

        for (let j = i; j < i + numbers[i]; j++) {
            if (numbers[j] !== numbers[i]) return false;
        }
        i += (numbers[i] - 1);
    }
    return true;
}

function generateNumber(cnt) {
    if (cnt === n) {
        if (checkIsBeautiful()) beautifulCnt++;
        return;
    }

    for (let i = 0; i < 4; i++) {
        numbers.push(i+1);
        generateNumber(cnt+1);
        numbers.pop();
    }
}

generateNumber(0);
console.log(beautifulCnt);