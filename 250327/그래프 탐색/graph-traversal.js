const fs = require("fs");
const input = fs.readFileSync(0).toString().trim().split('\n');

const [n, m] = input[0].split(' ').map(Number);
const edges = [];
for (let i = 1; i <= m; i++) {
    edges.push(input[i].split(' ').map(Number));
}


const graph = Array.from(Array(1001), () => Array());
const visited = Array(1001).fill(false);

edges.forEach(([x, y]) => {
    graph[x].push(y);
    graph[y].push(x);
});

let ans = 0;
visited[1] = true;

function dfs(vertex) {
    graph[vertex].forEach((curV) => {
        if (!visited[curV]) {
            ans++;
            visited[curV] = true;
            dfs(curV);
        }
    });
}

dfs(1);
console.log(ans);