#include <iostream>
using namespace std;

#define MAX_LEN 200

int arr[MAX_LEN];

int main() {
    int n, t;
    cin >> n >> t;

    for (int i = 0; i < 2*n; i++)
        cin >> arr[i];

    // for (int j = 2*n-1; j >= n; j--) {
    //     cin >> arr[j];
    // }

    for (int i = 0; i < t; i++) {
        int tmp = arr[2*n-1];
        // cout << tmp << endl;
        for (int i = 2*n-1; i >= 0; i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = tmp;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = n; i < 2*n; i++) {
        cout << arr[i] << " ";
    }
    // for (int j = 2*n-1; j >= n; j--) {
    //     cout << arr[j] << " ";
    // }

    return 0;
}