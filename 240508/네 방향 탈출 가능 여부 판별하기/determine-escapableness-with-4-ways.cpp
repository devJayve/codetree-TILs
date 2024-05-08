#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define MAX_LEN 100

int n, m;
bool visited[MAX_LEN][MAX_LEN];
int answer[MAX_LEN][MAX_LEN];
int grid[MAX_LEN][MAX_LEN];
queue<pair<int, int>> q;
int order = 1;

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool CanGo(int x, int y) {
    if (!InRange(x, y)) {
        return false;
    }
    if (visited[x][y] || grid[x][y] == 0) {
        return false;
    }
    return true;
}

void Push(int x, int y) {
    answer[x][y] = order++;
    visited[x][y] = true;
    q.push(make_pair(x, y));
}

void BFS() {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        pair<int, int> curr_pos = q.front();
        q.pop();

        int x = curr_pos.first;
        int y = curr_pos.second;
        for (int i  = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (CanGo(new_x, new_y))
                Push(new_x, new_y);
        }
    }
}



int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    Push(0,0);
    BFS();

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //                cout << answer[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << (answer[n-1][m-1] > 0 ? 1 : 0);

    return 0;
}