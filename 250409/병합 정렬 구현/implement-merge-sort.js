const fs = require("fs");
const input = fs.readFileSync(0).toString().trim().split('\n');

const n = Number(input[0]);
const arr = input[1].trim().split(' ').map(Number);

function merge(arr, low, mid, high) {
    let i = low;
    let j = mid + 1;
    let k = low;
    let mergedArr = Array(high - low + 1);

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            mergedArr[k] = arr[i];
            i++;
        } else {
            mergedArr[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        mergedArr[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        mergedArr[k] = arr[j];
        j++;
        k++;
    }

    for (k = low; k <= high; k++) {
        arr[k] = mergedArr[k];
    }
}

function mergeSort(arr, low, high) {
    if (low < high) {
        let mid = Math.floor((low + high)/ 2);
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
    return arr;
}

const sortedArr = mergeSort(arr, 0, arr.length - 1);
console.log(sortedArr.join(' '));