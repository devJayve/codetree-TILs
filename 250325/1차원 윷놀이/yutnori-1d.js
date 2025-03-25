const fs = require("fs");
const input = fs.readFileSync(0).toString().trim().split('\n');

const [n, m, k] = input[0].split(' ').map(Number);
const nums = input[1].split(' ').map(Number);

// 1) 말의 이동 경우의 수
const order = [];
let maxScore = 0;

function caculateScore() {
    const position = new Array(k).fill(1);

    for (let i = 0; i < n; i++) {
        position[order[i]] += nums[i];
    }

    const success = position.filter((value) => value >= m);
    return success.length;
}

function makeMoveOrder(cnt) {
    if (cnt === n) {
        const score = caculateScore();
        maxScore = Math.max(score, maxScore);
        return;
    }

    for (let i = 0; i < k; i++) {
        order.push(i);
        makeMoveOrder(cnt + 1);
        order.pop();
    }
}

makeMoveOrder(0);
console.log(maxScore);