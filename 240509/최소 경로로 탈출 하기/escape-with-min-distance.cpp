#include <iostream>
#include <utility>
#include <queue>
using namespace std;

#define MAX_LEN 100

queue<pair<int, int>> q;
int step[MAX_LEN][MAX_LEN];
int grid[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];

int n,m;

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void Push(int x, int y, int s) {
    step[x][y] = s;
    visited[x][y] = true;
    q.push(make_pair(x, y));
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


void BFS() {
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};

    while(!q.empty()) {
        pair<int, int> curr_pos = q.front();
        q.pop();

        int x = curr_pos.first;
        int y = curr_pos.second;

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            
            // cout << new_x << " " << new_y  << " " << CanGo(new_x, new_y) << endl;
            if (CanGo(new_x, new_y))
                Push(new_x, new_y, step[x][y] + 1);
        }
    }
}



int main() {
    cin >> n >> m;

    for (int i = 0; i< n; i++)
        for (int j = 0; j <m; j++)
            cin >> grid[i][j];

    Push(0,0, 0);
    BFS();

    

    // for (int i = 0; i< n; i++) {
    //     for (int j = 0; j <m; j++) {
    //         cout <<  step[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << (step[n-1][m-1] > 0 ? step[n-1][m-1] : -1);
    return 0;
}