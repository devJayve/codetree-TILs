#include <iostream>
#define DIV 1000000007
#define MAX_N 1000
using namespace std;

long long fillRect(int N) {
    long long dp[MAX_N + 1];
    dp[1] = 2;
    dp[2] = 7;
    dp[3] = 22;
    
    for (int i = 4; i <= N; i++) {
        dp[i] = dp[i-1] * 3 + 1;
        dp[i] %= DIV;
    }
    
    return dp[N];
}


int main() {
    int N;
    cin >> N;
    long long ans = fillRect(N);
    cout << ans << '\n';
    
}