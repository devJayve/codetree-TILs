const fs = require("fs");
const input = fs.readFileSync(0).toString().trim().split('\n');

const [n, m, k] = input[0].split(' ').map(Number);
const nums = input[1].split(' ').map(Number);

// 1) 말의 이동 경우의 수
let maxScore = 0;
const pieces = Array(k).fill(1);

function caculateScore() {
    return pieces.filter((piece) => piece >= m).length;
}

function makeMoveOrder(cnt) {
    maxScore = Math.max(maxScore, caculateScore());

    if (cnt === n) {
        return;
    }

    for (let i = 0; i < k; i++) {
        if (pieces[i] >= m) continue;

        pieces[i] += nums[cnt];
        makeMoveOrder(cnt + 1);
        pieces[i] -= nums[cnt];
    }
}

makeMoveOrder(0);
console.log(maxScore);