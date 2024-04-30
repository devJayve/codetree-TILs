#include <iostream>
using namespace std;

#define MAX_LEN 100

int ans[MAX_LEN][MAX_LEN];

int row, col;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool isRange(int x, int y) {
    return x >= 0 && x < col && y >= 0 && y < row;
}

int main() {
    cin >> row >> col;

    int num = 1;

    int x,y = 0;
    ans[x][y] = 1;
    int dir = 0;

    for (int i = 2; i <= row * col; i++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (!isRange(nx,ny) || ans[nx][ny] >= 1) {
            dir = (dir + 1) % 4;
        }
        x = x + dx[dir], y = y + dy[dir];
        ans[x][y] = i;   
    }
    

    for (int i = 0; i < row; i++) {
        for (int j =0; j < col; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}