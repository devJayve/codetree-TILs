#include <iostream>
#define MAX_N 45
using namespace std;

long long fibbo(int N) {
    long long dp[MAX_N + 1];
    
    dp[1] = 1;
    dp[2] = 1;
    
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[N];
}

int main() {
    int N;
    cin >> N;
    
    long long ans = fibbo(N);
    cout << ans << '\n';
    
    return 0;
}