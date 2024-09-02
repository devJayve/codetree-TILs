#include <iostream>
#define MAX 100
using namespace std;

int arr[MAX][MAX];
int tmp[MAX][MAX];

int N, M, Q;

void printMatrix() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void moveExternal(int r1, int c1, int r2, int c2) {
    int tmp = arr[r1][c1];
    
    // 좌측 이동
    for (int i = r1; i < r2; i++) {
        arr[i][c1] = arr[i+1][c1];
    }
    
    // 하단 이동
    for (int i = c1; i < c2; i++) {
        arr[r2][i] = arr[r2][i+1];
    }
    
    // 우측 이동
    for (int i = r2; i > r1; i--) {
        arr[i][c2] = arr[i-1][c2];
    }
    
    // 상단 이동
    for (int i = c2; i > c1+1; i--) {
        arr[r1][i] = arr[r1][i-1];
    }
    
    arr[r1][c1+1] = tmp;
}

void changeValueToAvg(int r1, int c1, int r2, int c2) {
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            int sum = arr[i][j];
            int cnt = 1;
            
            if (i-1 >= 1) {
                sum += arr[i-1][j];
                cnt++;
            }
            if (j-1 >= 1) {
                sum += arr[i][j-1];
                cnt++;
            }
            if (i+1 <= N) {
                sum += arr[i+1][j];
                cnt++;
            }
            if (j+1 <= M) {
                sum += arr[i][j+1];
                cnt++;
            }
            
            tmp[i][j] = sum /= cnt;
        }
    }
    
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            arr[i][j] = tmp[i][j];
        }
    }
}

int main() {
    cin >> N >> M >> Q;
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> arr[i][j];
    
    while (Q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        
        // 1) 경계 숫자 방향으로 회전
        moveExternal(r1, c1, r2, c2);
        
        // 2) 직사각형 내부 값 평균으로 변환
        changeValueToAvg(r1, c1, r2, c2);
    }
    
    printMatrix();
    
    return 0;
}