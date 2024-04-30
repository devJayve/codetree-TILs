#include <iostream>
using namespace std;

int matrix[100][100];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool inRange(int x, int y, int n) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

int countNumber(int x, int y, int n) {
    int cnt = 0;
    for (int dir_num = 0; dir_num < 4; dir_num++) {
        int nx = x + dx[dir_num], ny = y + dy[dir_num];
        if (inRange(x,y,n) && matrix[nx][ny] == 1) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            matrix[i][j] = num;
        }
    }

    int cnt_more_3 = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cnt = countNumber(i,j,n);
            if (cnt >= 3) {
                cnt_more_3++;
            }
        }
    }

    cout << cnt_more_3;


    
            



    return 0;
}