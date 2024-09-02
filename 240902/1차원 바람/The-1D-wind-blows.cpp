#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX][MAX];
int N, M, Q, r;
char d;
int dirArr[2] = {1, 0};

void printMatrix() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


void moveArr(int col, int dir) {
    int tmp;
    if (dir == 0) {
        tmp = arr[col][M-1];
        
        for (int i = M-2; i >= 0; i--) {
            arr[col][i+1] = arr[col][i];
        }
        
        arr[col][0] = tmp;
    } else {
        tmp = arr[col][0];
        
        for (int i = 1; i < M; i++) {
            arr[col][i-1] = arr[col][i];
        }
        
        arr[col][M-1] = tmp;
    }
}

void moveTop(int col, int dir) {
    moveArr(col, dir);
    
    for (int i = 0; i < M; i++) {
        if (col > 0 && arr[col][i] == arr[col-1][i]) {
            moveTop(col-1, dirArr[dir]);
            break;
        }
    }
}

void moveDown(int col, int dir) {
    moveArr(col, dir);
    
    for (int i = 0; i < M; i++) {
        if (col < N-1 && arr[col][i] == arr[col+1][i]) {
            moveDown(col+1, dirArr[dir]);
            break;
        }
    }
}


int main() {
    cin >> N >> M >> Q;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];
    
    while (Q--) {
        cin >> r >> d;
        
        int col = r - 1;
        int dir = d == 'R';
        moveArr(col, dir);
        
        
        for (int i = 0; i < M; i++) {
            if (col > 0 && arr[col][i] == arr[col-1][i]) {
                moveTop(col-1, dirArr[dir]);
                break;
            }
        }
        
        for (int i = 0; i < M; i++) {
            if (col < N-1 && arr[col][i] == arr[col+1][i]) {
                moveDown(col+1, dirArr[dir]);
                break;
            }
        }
    }
    
    printMatrix();
    
    return 0;
}