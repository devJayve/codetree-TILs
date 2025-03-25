const fs = require("fs");
const input = fs.readFileSync(0).toString().trim().split('\n');
const n = Number(input[0]);
const segments = input.slice(1, 1 + n).map(line => line.split(' ').map(Number));

let ans = 0;
let lines = [];
let visited = new Array(n).fill(false);
let map = new Map();

// 1) 선분을 뽑는 경우의 수
function pickLine(cnt) {
    if (cnt <= n) {
        lines.sort((a,b) => a-b);
        const key = lines.join('');

        if (!map.has(key)) {
            map.set(key, 1);
            if (!checkIsOverlap(lines)) {
                ans = Math.max(ans, lines.length);
            }
        }
        if (cnt === n) return;
    }

    for (let i = 0; i < n; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        lines.push(i);    
        
        pickLine(cnt + 1);

        lines.pop();
        visited[i] = false;
    }
}

// 2) 선분이 겹쳤는지 확인
function checkIsOverlap() {
    if (lines.length === 0) return true;

    let fullLine = [];
    for (let i = 0; i < lines.length; i++) {
        fullLine.push(segments[lines[i]]);
    }

    fullLine.sort((a, b) => a[0] - b[0]);

    let line1 = fullLine[0];
    
    for (let i = 1; i < fullLine.length; i++) {
        if (line1[1] >= fullLine[i][0]) return true;
        line1 = fullLine[i];
    }
    return false;
}

pickLine(0);
console.log(ans);