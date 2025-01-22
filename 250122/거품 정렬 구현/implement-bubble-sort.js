const fs =require("fs");

let input = fs.readFileSync(0).toString().split('\n');
let n = parseInt(input[0]);
let arr = input[1].split(' ').map(Number);


for (let i = 0; i < arr.length; i++) {
    for (let j = 0; j < arr.length -i; j++) {
        if (arr[j] > arr[j+1]) {
            let tmp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = tmp;
        }
    }
}



const answer = arr.map(String).join(' ');
console.log(answer);