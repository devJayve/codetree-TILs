#include <iostream>
using namespace std;

#define DIR_LEN 4

int dx[DIR_LEN] = {1,-1,0,0}; // 동서남북
int dy[DIR_LEN] = {0,0,-1,1};

int getDir(char value) {
    if (value == 'E') {
        return 0;
    } else if (value == 'W') {
        return 1;
    } else if (value == 'S') {
        return 2;
    } else {
        return 3;
    }
}

int main() {
    int n;
    cin >> n;

    int cnt = 0;

    int x = 0;
    int y = 0;

    while (n--) {
        char dir;
        int dir_cnt;
        cin >> dir >> dir_cnt;

        int dir_num = getDir(dir);

        for (int i = 0; i < dir_cnt; i++) {
            x = x + dx[dir_num], y = y + dy[dir_num];
            cnt++;
            if (x == 0 && y == 0) {
                break;
            }
            
        }
        if (x == 0 && y == 0) {
            break;
        }
    }

    if (x == 0 && y == 0) {
        cout << cnt;
    } else {
        cout << -1;
    }
    
    return 0;
}