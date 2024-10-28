#include <iostream>
#define DIV 1000000007
#define MAX_N 1000
using namespace std;

long long fillRect(int N) {
    long long dp[MAX_N + 1];
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;
    
    for (int i = 3; i <= N; i++) {
        dp[i] = (2 * dp[i-1] + 3 * dp[i-2]) % DIV;
        for (int j = i-3; j >= 0; j--) {
            dp[i] += 2 * dp[j] % DIV;
        }
    }
    
    return dp[N];
}


int main() {
    int N;
    cin >> N;
    long long ans = fillRect(N);
    cout << ans << '\n';
    
}