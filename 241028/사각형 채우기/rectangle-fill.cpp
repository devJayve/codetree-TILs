#include <iostream>
#define MAX_N 1000
#define DIV 10007
using namespace std;

long long fillRect(int N) {
    long long dp[MAX_N + 1];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
    for (int i = 4; i <= N; i++) {
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= DIV;
    }
    
    return dp[N];
}

int main() {
    int N;
    cin >> N;
    
    long long ans = fillRect(N);
    cout << ans << '\n';
    
    return 0;
}