#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countCoin(int col, int row, vector<vector<int>> matrix) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[col+i][row+j] == 1) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> matrix;

    for (int i = 0; i < N; i++) {
        vector<int> v;
        for (int j = 0; j < N; j++) {
            int n;
            cin >> n;
            v.push_back(n);
        }
        matrix.push_back(v);
    }
    
    int maxCount= 0;


    for (int col = 0; col < N; col++) {
        for (int row = 0; row < N; row++) {
            if (N - col < 3 || N - row < 3) {
                continue;
            }
            maxCount = max(countCoin(col, row, matrix), maxCount);
        }
    }

    cout << maxCount;
    return 0;
}