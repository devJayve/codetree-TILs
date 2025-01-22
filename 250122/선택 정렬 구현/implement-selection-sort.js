const fs = require("fs");

const input = fs.readFileSync(0).toString().trim().split('\n');
let n = input[0];
let arr = input[1].split(' ').map(Number);

for (let i = 0; i < n; i++) {
    let min = i;
    for (let j = i; j < n; j++) {
        if (arr[j] < arr[min]) {
            min = j;
        }
    }
    let tmp = arr[i];
    arr[i] = arr[min];
    arr[min] = tmp;
}

let answer = arr.join(' ');
console.log(answer);