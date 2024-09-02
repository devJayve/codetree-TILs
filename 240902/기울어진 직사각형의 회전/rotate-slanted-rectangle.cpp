#include <iostream>
#define MAX 100
using namespace std;

int arr[MAX][MAX];
int m[4];

int n;
int r, c; // 시작 좌표

int dir; // 0일 시 반시계 방향, 1일 시 시계 방향

int dx[4] = {-1, -1, 1, 1};
int dy[4] = {1, -1, -1, 1};

void roateClockWise() {
    int tmp = arr[r][c];
    
    int x = r;
    int y = c;
    m[3]--;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < m[i]; j++) {
            arr[x][y] = arr[x+dx[i]][y+dy[i]];
            x += dx[i];
            y += dy[i];
        }
    }
    
    arr[x][y] = tmp;
}

void rotateCounterClockWise() {
    int tmp = arr[r][c];
    
    int x = r;
    int y = c;
    m[0]--;
    
    
    for (int i = 3; i >= 0; i--) {
        int idx = (i+2)%4;
        cout << idx << endl;
        
        for (int j = 0; j < m[i]; j++) {
            arr[x][y] = arr[x+dx[idx]][y+dy[idx]];
            x += dx[idx];
            y += dy[idx];
        }
    }
    
    arr[x][y] = tmp;
}

void printMatrix() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    
    cin >> r >> c;
    for (int i = 0; i < 4; i++)
        cin >> m[i];
    cin >> dir;
    
    dir ? roateClockWise() : rotateCounterClockWise();
    
    printMatrix();
}