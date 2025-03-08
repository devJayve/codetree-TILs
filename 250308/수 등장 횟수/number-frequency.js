const fs = require("fs");
const input = fs.readFileSync(0).toString().trim().split('\n');

const [n, m] = input[0].split(' ').map(Number);
const arr = input[1].split(' ').map(Number);
const queries = input[2].split(' ').map(Number);

const map = new Map();

for (let i = 0; i < n; i++) {
    const num = arr[i];
    const result = map.get(num);    
    if (!result) map.set(num, 1);
    else map.set(num, Number(result) + 1);
}

const ans = new Array(m);

for (let i = 0; i < m; i++) {
    const res = map.get(queries[i]);
    ans[i] = res ?? 0;
}

console.log(ans.join(' '));