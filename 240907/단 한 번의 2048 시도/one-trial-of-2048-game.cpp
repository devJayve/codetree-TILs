/*
 단 한번의 2048 시도
 */

#include <iostream>
#define SIZE 4
using namespace std;

int arr[SIZE+1][SIZE+1];

void printMatrix() {
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}

void move() {
    int tmp[SIZE+1][SIZE+1] = {0, };
    
    for (int i = 1; i <= SIZE; i++) {
        int row = SIZE;
        for (int j = row; j >= 1; j--) {
            if (arr[i][j] != 0) {
                tmp[i][row] = arr[i][j];
                if (j-1 >= 1 && arr[i][j] == arr[i][j-1]) {
                    tmp[i][row] *= 2; 
                     j--;
                }
                row--;
            }
        }
    }
    
    for (int i = 1; i <= SIZE; i++)
        for (int j = 1; j <= SIZE; j++)
            arr[i][j] = tmp[i][j];
}

void rotate() {
    int tmp[SIZE+1][SIZE+1];
    
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            tmp[j][SIZE+1-i] = arr[i][j];
        }
    }
    
    for (int i = 1; i <= SIZE; i++)
        for (int j = 1; j <= SIZE; j++)
            arr[i][j] = tmp[i][j];
}


int main() {
    char dir;
    
    for (int i = 1; i <= SIZE; i++)
        for (int j = 1; j <= SIZE; j++)
            cin >> arr[i][j];
    
    cin >> dir;
    
    switch (dir) {
        case 'D':
            rotate();
        case 'L':
            rotate();
        case 'U':
            rotate();
        case 'R':
            move();
            break;
        default:
            break;
    }
    
    switch (dir) {
        case 'U':
            rotate();
        case 'L':
            rotate();
        case 'D':
            rotate();
        case 'R':
            printMatrix();
            break;
        default:
            break;
    }
    
    return 0;
}