#include <iostream>
using namespace std;

#define MAX_LEN 100

int arr[MAX_LEN][MAX_LEN];
int answer[MAX_LEN][MAX_LEN];
int visited[MAX_LEN][MAX_LEN];
int order = 1;
int n;

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y) {
    if (!InRange(x, y))
        return false;
    if (visited[x][y] || arr[x][y] == 0)
        return false;
    return true;
} 

void DFS(int x, int y) {
    int dx[2] = {1, 0};
    int dy[2] = {0, 1};

    for (int i = 0; i < 2; i++) {
        int new_x = x +dx[i];
        int new_y = y + dy[i];

        if(CanGo(new_x, new_y)) {
            answer[new_x][new_y] = order++;
            visited[new_x][new_y] - 1;
            DFS(new_x, new_y);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i <n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    DFS(0,0);

    cout << answer[n-1][n-1];
    
    return 0;
}