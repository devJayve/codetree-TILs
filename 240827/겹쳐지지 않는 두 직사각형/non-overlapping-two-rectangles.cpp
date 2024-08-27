#include <iostream>
#include <cstdio>
#include <limits>
using namespace std;
#define MAX 5


/*
 algorithm
 1) 첫 번째 직사각형을 선택한다.
 2) 첫 번째 직사각형 영역 외에 두 번째 직사각형을 선택한다.
 3) 직사각형의 좌표는 출발 좌표와 도착 좌표를 통해 그린다.
 4) 출발 좌표와 도착 좌표 영역 내에 다른 직사각형이 있을 시 넘어간다.
 */

int arr[MAX][MAX];
int n, m;

bool inFirstBoxRange(int fx1, int fy1, int fx2, int fy2, int sx1, int sy1, int sx2, int sy2) {
    for (int i = fx1; i <= fx2; i++) {
        for (int j = fy1; j <= fy2; j++) {
            for (int k = sx1; k <= sx2; k++) {
                for (int l = sy1; l <= sy2; l++) {
                    if (i == k && j == l) return true;
                }
            }
        }
    }
    return false;
}

int getRectSum(int x1, int y1, int x2, int y2) {
    int sum = 0;
    
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}


int main() {
    int ans = numeric_limits<int>::min();
    
    cin >> n >> m;
    
    // 배열을 입력받는다.
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
                    // 첫 번째 직사각형의 합을 구한다.
                    if (i > k || j > l) continue;
                    int firstRectSum = getRectSum(i, j, k, l);
                    
                    for (int o = 0; o < n; o++) {
                        for (int p = 0; p < m; p++) {
                            for (int q = 0; q < n; q++) {
                                for (int r = 0; r < m; r++) {
                                    if (inFirstBoxRange(i, j, k, l, o, p, q, r)) continue;
                                    if (o > q || p > r) continue;
                    
                                    // 두 번째 직사각형의 합을 구한다.
                                    int secondRectSum = getRectSum(o, p, q, r);
                                    
                                    ans = max(ans, (firstRectSum+secondRectSum));
                                    
//                                        printf("first pos : %d %d %d %d\n", i, j, k, l);
//                                        printf("sec pos : %d %d %d %d\n", o, p, q, r);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << ans;
    
    
    
    return 0;
}