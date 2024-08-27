#include <iostream>
#define MAX 400
using namespace std;

int arr[MAX];
int n, t;

int main() {
    int tmp[200];
    
    cin >> n >> t;
    
    for (int i = 0; i < 2*n; i++)
            cin >> arr[i];
    
    t %= 2*n;
    
    for (int i = 0; i < t; i++) {
        tmp[i] = arr[2*n-t+i];
    }
    
    for (int i = 2*n-t-1; i >= 0; i--) {
        arr[i+t] = arr[i];
    }
    
    // 임시 배열 할당
    for (int i = 0; i < t; i++) {
        arr[i] = tmp[i];
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << endl;
    
    for (int i = n; i < 2*n; i++) {
        cout << arr[i];
    }
    
    
    
    
        
    return 0;
}