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
        return memo[n];
    }
    if (memo[n] == -1) {
        return Fibo(n-1) + Fibo(n-2);
    }
}

int main() {
    memo[1] = 1;
    memo[2] = 1;
    
    int n;
    cin >> n;
    cout <<Fibo(n);
}