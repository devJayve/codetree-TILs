const fs =require("fs");

let input = fs.readFileSync(0).toString().split('\n');
let n = parseInt(input[0]);
const arr = input[1].split(' ').map(Number);

while (n > 0) {
    n -= 1;
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] > arr[i+1]) {
            let tmp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = tmp;
        }
    }
}

const answer = arr.map(String).join(' ');
console.log(answer);