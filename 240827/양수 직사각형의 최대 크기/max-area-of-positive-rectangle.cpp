#include <iostream>
#include <limits>
#define MAX 20
using namespace std;

int arr[MAX][MAX];
int n, m;

int getRectSum(int x1, int y1, int x2, int y2) {
    int sum = 0;
    
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (arr[i][j] <= 0) return -1;
            
            sum += arr[i][j];
        }
    }
    
    return sum;
}

/*
 - 직사각형 크기가 최대
 - 내부에 모든 수가 양수여야 함
 */

int main() {
    int ans = -1;
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < m; l++) {
                    int sum = getRectSum(i, j, k , l);
                    if (sum < 0) continue;
                    
                    int rectSize = (k - i + 1) * (l - j + 1);
                    ans = max(rectSize, ans);
                }
            }
        }
    }
    
    cout << ans;
    
    return 0;
}