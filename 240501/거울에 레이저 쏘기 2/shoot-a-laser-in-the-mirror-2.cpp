#include <iostream>
using namespace std;

#define MAX_LEN 1000
#define DIR_LEN 4

char arr[MAX_LEN][MAX_LEN];

int dx[DIR_LEN] = {0,-1,1,0}; 
int dy[DIR_LEN] = {1,0,0,-1};

int replace1[DIR_LEN] = {2,3,0,1};
int replace2[DIR_LEN] = {1,0,3,2};
int replace3[DIR_LEN] = {3,2,1,0};

int n;

bool isRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
    int point, dir;

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

        
    cin >> point;
    point -=1;

    int cnt = 1;

    int x,y;

    if (point / n == 0) {
        x = 0, y = point;
        dir = 1;    
    } else if (point / n == 1) {
        x= point, y = n;
        dir = 0;
    } else if (point / n == 2) {
        x = n, y = point;
        dir = 2;
    } else if (point / n == 3) {
        x = point, y = 0;
        dir = 3;
    }

    // cout << x << " " << y << " " << dir << endl;
    for (int i = 0; i < n*n; i++) {
        // dir 반사
        if (arr[x][y] == '/') {
            dir = replace1[dir];
        } else {
            dir = replace2[dir];
        }
        int nx = x + dx[dir], ny = y + dy[dir];
        // cout << nx << " " << ny << " " << dir << endl;
        if (!isRange(nx, ny)) break;
        x = x + dx[dir], y = y + dy[dir];
        cnt++;
        // dir을 반대편 dir로 전환

        dir= replace3[dir];
    }

    cout << cnt;



    



    return 0;
}