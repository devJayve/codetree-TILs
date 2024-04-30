#include <iostream>
using namespace std;

#define MAX_LEN 100
#define DIR_LEN 4

int ans[MAX_LEN][MAX_LEN];
int dx[DIR_LEN] = {0,1,0,-1};
int dy[DIR_LEN] = {1,0,-1,0};

int n,m;

bool isRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    cin >> n >> m;

    int x,y = 0;
    int dir = 0;
    ans[x][y] = 1;

    for (int i = 2; i <= n*m; i++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (!isRange(nx, ny) || ans[nx][ny] != 0) {
            dir = (dir + 1) % 4;
        }
        x = x + dx[dir], y = y + dy[dir];
        ans[x][y] = i;
    }

    for (int i = 0; i< n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}