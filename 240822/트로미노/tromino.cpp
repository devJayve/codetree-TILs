#include <iostream>
using namespace std;

#define MAX 200

int arr[MAX][MAX];
int n, m;


int main() {
    int maxSum = 0;
    
    cin >> n >> m;
    
    for (int i = 0; i <n; i++)
        for (int j =0; j <m; j++)
            cin >> arr[i][j];
            
    // 첫 번째 블럭에 대한 합
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < n-1 && j < m-1) {
                int seq[4] = {arr[i][j], arr[i][j+1], arr[i+1][j], arr[i+1][j+1]};
                for (int l = 0; l < 4; l++) {
                    int sum = seq[0] + seq[1] + seq[2] + seq[3] - seq[l];
                    maxSum = max(sum, maxSum);
                }
            }
        }
    }
    
    // 두 번째 블럭에 대한 합
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 세로 블럭
            if (i+2 < n) {
                int sum = arr[i][j] + arr[i+1][j] + arr[i+2][j];
                maxSum = max(sum, maxSum);
            }
            // 가로 블럭
            if (j+2 < m)
            {
                int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2];
                maxSum = max(sum, maxSum);
            }
        }
    }
    
    cout << maxSum;
    
    
    return 0;
}