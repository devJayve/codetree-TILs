const fs = require("fs");
const input = fs.readFileSync(0).toString().trim().split('\n');

const n = Number(input[0]);
const grid = input.slice(1, 1 + n).map(line => line.split(' ').map(Number));

let maxCnt = 0;
const bombs = [];
const selectedBombs = [];
const bombDir = [
    [[-1,0],[-2,0],[1,0],[2,0]],
    [[-1,0],[1,0],[0,-1],[0,1]],
    [[-1,-1],[-1,1],[1,-1],[1,1]], 
]

// 1) 폭탄 개수 및 위치 찾기
function findBombs() {
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) bombs.push([i, j]);
        }
    }
}

// 2) 폭탄을 놓는 경우의 수 계산
function generateBomb(cnt) {
    if (cnt === bombs.length) {
        calculateCnt();
        return;
    }

    for (let i = 0; i < 3; i++) {
        selectedBombs.push(i);
        generateBomb(cnt + 1);        
        selectedBombs.pop();
    }
}


// 3) 폭탄이 놓였을 때의 폭발 영역 수 계산
function calculateCnt() {
    let visited = Array.from(new Array(n), () => new Array(n).fill(false));
    let cnt = 0;

    for (let i = 0; i < bombs.length; i++) {
        const [curX, curY] = bombs[i];
        
        if (!visited[curX][curY]) {
            visited[curX][curY] = true;
            cnt++;
        }

        const bombNum = selectedBombs[i];

        for (let i = 0; i < 4; i++) {
            const [dirX, dirY] = bombDir[bombNum][i];
            const nextX = curX + dirX;
            const nextY = curY + dirY; 

            if (isCanGo(nextX, nextY) && !visited[nextX][nextY]) {    
                cnt++;
                visited[nextX][nextY] = true;
            }
        }
    }
    
    maxCnt = Math.max(cnt, maxCnt);
}

function isCanGo(x, y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

findBombs();
generateBomb(0);
console.log(maxCnt);

