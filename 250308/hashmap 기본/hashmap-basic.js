const fs = require("fs");
const input = fs.readFileSync(0).toString().trim().split('\n');

const n = Number(input[0]);

console.log(input[1]);
// const commands = input[1].split(' ').map(String);

const map = new Map();

// for (let i = 0; i < n; i++) {
//     switch(commands[i]) {
//         case "add":

//             map.set('')
//             break;
//         case "remove":
//             break;
//         case "find":
//             break;
//         default:
//             throw new Error('unsupported Command!', commands[i]);
//     }
// }