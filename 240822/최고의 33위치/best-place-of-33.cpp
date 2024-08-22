#include <iostream>
#include <algorithm>
using namespace std;

#define N 100

int n;
int arr[N][N];

int getCount(int x, int y) {
    int count = 0;
    for (int i = x; i < x+3; i++) {
        for (int j = y; j < y+3; j++) {
            if (arr[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

bool isAvailableBound(int x, int y) {
    return (x >= 0 && n-x > 2 && y >= 0 && n-y > 2);
}

int main() {
    int maxCount = 0;
    cin >> n;

    // 초기화
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isAvailableBound(i, j)) {
                int count = getCount(i ,j);
                maxCount = max(count, maxCount);
            }
        }
    }

    cout << maxCount;

    return 0;
}