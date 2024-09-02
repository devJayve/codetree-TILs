#include <iostream>
using namespace std;

int n, t;
int arr[600];
int tmp[600];

void printMatrix() {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    for (int i = n; i < n*2; i++)
        cout << arr[i] << " ";
    cout << endl;
    for (int i = n*2; i < n*3; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void moveArr() {
    for (int i = 0; i < t; i++)
        tmp[i] = arr[n*3-t+i];
    
    for (int i = n*3-1; i >= t; i--)
        arr[i] = arr[i-t];
    
    for (int i = 0; i < t; i++)
        arr[i] = tmp[i];
}

int main() {
    cin >> n >> t;
    
    for (int i = 0; i < n*3; i++)
        cin >> arr[i];
    
    t %= n*3;
    
    moveArr();
    
    printMatrix();
    
    return 0;
}