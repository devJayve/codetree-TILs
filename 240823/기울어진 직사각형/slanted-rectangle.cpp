#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 20
int arr[MAX][MAX];
int n;

int dx[4] = {-1,-1,1,1};
int dy[4] = {1,-1,-1,1};

bool isAvailableRange(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int getMoveSum(int x, int y) {
    int maxSum = 0;
    int sum = 0;
    int tmp = 0;
    
    int curX = x;
    int curY = y;
    
    for (int i = 1; i < n; i++) {
        sum = 0;
        tmp = 0;
        if (!isAvailableRange(curX + dx[0] * i, curY + dy[0] * i)) continue;
        for (int j = 0; j < i; j++) {
            // 1번 방향 이동
            curX += dx[0];
            curY += dy[0];
            sum += arr[curX][curY];
        }
        tmp = sum;
        
        for (int j = 1; j <= n-i; j++) {
            sum = tmp;
            
            if (!isAvailableRange(curX + dx[1], curY + dy[1])) continue;
            
            for (int k = 0; k < j; k++) {
                // 2번 방향 이동
                curX += dx[1];
                curY += dy[1];
                sum += arr[curX][curY];
            }
            
            // 각각 동일한 횟수로 3,4번 방향으로 이동 가능한지 확인
            for (int l = 0; l < i; l++) {
//                if (x==2 && y==0 && i==1) {
//                    cout << curX << " " << curY << endl;
//                }
                if (!isAvailableRange(curX + dx[2], curY + dy[2])) goto endOfLoop;
                curX += dx[2];
                curY += dy[2];
                sum += arr[curX][curY];
            }
            for (int k = 0; k < j; k++) {
                if (!isAvailableRange(curX + dx[3], curY + dy[3])) goto endOfLoop;
                curX += dx[3];
                curY += dy[3];
                sum += arr[curX][curY];
            }
            maxSum = max(sum, maxSum);
//            if (sum == 36) {
//                cout << "position" << x <<  " " << y  << " " << i << endl;
//            }
        }
    }
    endOfLoop:

    return maxSum;
}

int main() {
    int maxMoveSum = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        for (int j =0; j <n; j++)
            cin >> arr[i][j];
    
    for (int i = 0; i < n; i++){
        for (int j =0; j <n; j++) {
            int moveSum = getMoveSum(i, j);
            maxMoveSum = max(moveSum, maxMoveSum);
        }
    }
    
    cout << maxMoveSum;
    
    return 0;
}