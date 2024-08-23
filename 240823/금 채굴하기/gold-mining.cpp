#include <iostream>
using namespace std;

#define MAX 20
int arr[MAX][MAX];
bool found[MAX][MAX];
int n, m; // n = 정사각형 크기, m = 금 한개의 가격

int getGold(int x, int y, int K) {
    int goldCnt = 0;
    for (int i = 0; i < K+1; i++) {
        for (int j = y-i; j <= y+i; j++) {
            if (x+i-K < 0 || x+i-K >= n || j < 0 || j >= n) continue;
            if (!found[x+i-K][j] && arr[x+i-K][j] == 1) {
                goldCnt++;
                found[x+i-K][j] = 1;
            }
            if (!found[x-i+K][j] && arr[x-i+K][j] == 1) {
                goldCnt++;
                found[x-i+K][j] = 1;
            }
        }
    }
    return goldCnt;
}


void initializeFound() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            found[i][j]= false;
}

int main() {
    int goldMaxCnt = 0;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int K = 0; K <= 2*n-1; K++) {
                initializeFound();
                int goldCnt = getGold(i, j , K);
                int totalCost = (goldCnt * m) - (K * K + (K+1) * (K+1));
                if (totalCost >= 0) {
                    goldMaxCnt = max(goldCnt, goldMaxCnt);
                }
            }
        }
    }
    
    cout << goldMaxCnt;
    
    
    return 0;
}