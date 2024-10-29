#include <iostream>
#define MAX_N 1000
using namespace std;

int graph[MAX_N + 1][MAX_N + 1];
bool visited[MAX_N + 1];
int N, M;
int ans;

void dfs(int vertex) {
    for (int i = 1; i <= N; i++) {
        if (graph[vertex][i] && !visited[i]) {
            visited[i] = true;
            ans++;
            dfs(i);
        }
    }
}

int main() {
    int x, y;
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    
    visited[1] = true;
    dfs(1);
    
    cout << ans;
    
    return 0;
}