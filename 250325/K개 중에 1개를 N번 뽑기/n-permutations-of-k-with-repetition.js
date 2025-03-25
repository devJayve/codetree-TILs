const fs = require("fs");
const input = fs.readFileSync(0).toString().trim().split('\n');
const [k, n] = input[0].split(' ').map(Number);

// 1~K, N번

function generateNumber(k, n, cur, arr) {
    if (cur === n) {
        console.log(arr.join(' '));
        return;
    }

    for (let i = 0; i < k; i++) {
        arr.push(i + 1);
        generateNumber(k, n, cur + 1, arr);
        arr.pop();
    }
}

generateNumber(k, n, 0, []);