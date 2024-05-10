#include <iostream>
using namespace std;

#define MAX_LEN 45

int arr[MAX_LEN];

int main() {
    int n;
    cin >> n;

    arr[0] = 1;
    arr[1] == 1;

    if (n >= 2) {
        for (int i = 2; i <= n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    }

    cout << arr[n];

    return 0;
}