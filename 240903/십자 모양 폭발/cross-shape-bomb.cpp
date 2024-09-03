#include <iostream>
#define MAX_N 200
using namespace std;

int arr[MAX_N][MAX_N];
int tmp[MAX_N][MAX_N];
int n;

void printMatrix() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << tmp[i][j] << " ";
        }
        cout << endl;
    }
}

bool isBombRange(int col, int row, int r, int c, int bombCnt) {
    return (col == r && row >= c-bombCnt && row <= c+bombCnt)
    || (row == c && col >= r-bombCnt && col <= r+bombCnt);
}

int main() {
    int r, c;
    
    cin >> n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    cin >> r >> c; r--; c--;
    
    int bombCnt = --arr[r][c];
    
    for (int row = 0; row < n; row++) {
        int tmpCol = n-1;
        for (int col = n-1; col >= 0; col--) {
            if (isBombRange(col, row, r, c, bombCnt)) {
                continue;
            };
            tmp[tmpCol--][row] = arr[col][row];
        }
    }
    
    printMatrix();
    
    return 0;
}