#include <iostream>
using namespace std;

#define N 100
int arr[N][N];
int m,n;

bool isHappyNumsFromCol(int x) {
    if (m == 1) return true;
    int contiCount = 0;
    int lastValue = -1;
    
    for (int i = 0; i < n; i++) {
        if (arr[x][i] == lastValue) {
            contiCount++;
            if (contiCount >= m) return true;
        }
        else {
            contiCount = 1;
        }
        lastValue = arr[x][i];
    }
    return false;
}

bool isHappyNumsFromRow(int y) {
    if (m == 1) return true;
    int contiCount = 0;
    int lastValue = -1;
    
    for (int i = 0; i < n; i++) {
        if (arr[i][y] == lastValue) {
            contiCount++;
            if (contiCount >= m) return true;
        }
        else {
            contiCount = 1;
        }
        lastValue = arr[i][y];
    }
    return false;
}




int main() {
    int happyNumsCount = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    for (int i = 0; i < n; i++) {
        if (isHappyNumsFromRow(i)) happyNumsCount++;
        if (isHappyNumsFromCol(i)) happyNumsCount++;
    }
    
    cout << happyNumsCount;
    
    return 0;
}