#include <iostream>
using namespace std;

#define MAX_LEN 100
#define DIR_LEN 4

int N;

int arr[MAX_LEN][MAX_LEN];

int dx[DIR_LEN] = {1,0,-1,0};
int dy[DIR_LEN] = {0,-1,0,1};

bool isRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool checkIsComfortable(int x, int y) {
    int cnt = 0;
    for (int dir = 0; dir < DIR_LEN; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (isRange(nx,ny) && arr[nx][ny] == 1) {
            cnt++;
        }
    }
    return cnt == 3;
}

int main() {
    int M;
    cin >> N >> M;

    for (int i = 0; i< M; i++) {
        int x, y;
        cin >> x >> y;
        arr[x-1][y-1] = 1;
        cout << (checkIsComfortable(x-1,y-1) ? 1 : 0) << endl;        
    }

    return 0;
}