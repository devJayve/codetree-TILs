#include <iostream>
using namespace std;

#define MAX_LEN 45

int arr[MAX_LEN];
int memo[MAX_LEN];

//  tabulation
// int main() {
//     int n;
//     cin >> n;

//     arr[0] = 1;
//     arr[1] = 1;

//         for (int i = 2; i <= n; i++) {
//         arr[i] = arr[i-1] + arr[i-2];
//     }

//     cout << arr[n-1];

//     return 0;
// }

// recursion + memoization

int Fibo(int n) {
    if (memo[n] != -1) {
        return memo[n];
    }
    if (n <= 2) {
        memo[n] = 1;
    }
    else {
        memo[n] = Fibo(n-1) + Fibo(n-2);
    }
    return memo[n];
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        memo[i] = -1;
    }
    
    cout << Fibo(n);
}