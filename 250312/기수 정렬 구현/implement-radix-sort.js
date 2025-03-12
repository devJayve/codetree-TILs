const fs = require("fs");
const input = fs.readFileSync(0).toString().trim().split('\n');

const n = Number(input[0]);
const arr = input[1].split(' ').map(String);


function radixSort(arr) {
    let isDone = false;
    let curDigit = 1;

    while (!isDone) {
        isDone = true;
        const newArr = Array.from(Array(10), () => Array());

        for (let i = 0; i < arr.length; i++) {
            const digit = arr[i].charAt(arr[i].length - curDigit);
            if (digit) isDone = false;
            newArr[Number(digit)].push(arr[i]);
        }

        arr = newArr.flat();
        curDigit++;
    }
    return arr;
}

const sortedArr = radixSort(arr);
const ans = sortedArr.join(' ');
console.log(ans);