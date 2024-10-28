#include <iostream>
#define DIV 10007
#define MAX_N 1000
using namespace std;

long long climbStep(int N) {
    long long dp[MAX_N + 1];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= N; i++) {
        dp[i] = dp[i-2] + dp[i-3];
        dp[i] %= DIV;
    }
    return dp[N];
}

int main() {
    int N;
    cin >> N;
    
    long long ans = climbStep(N);
    cout << ans << '\n';
    
    return 0;
}