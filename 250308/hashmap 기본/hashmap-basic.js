const fs = require("fs");
const input = fs.readFileSync(0).toString().trim().split('\n');

const n = Number(input[0]);

const map = new Map();

for (let i = 1; i <= n; i++) {
    const commands = input[i].split(' ').map(String);

    switch(commands[0]) {
        case "add":
            map.set(commands[1], commands[2]);
            break;
        case "remove":
            map.delete(commands[1]);
            break;
        case "find":
            const result = map.get(commands[1]);
            if (result) console.log(result);
            else console.log('None');
            break;
        default:
            throw new Error('unsupported Command!', commands[0]);
    }
}