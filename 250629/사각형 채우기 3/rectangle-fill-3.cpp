#include <bits/stdc++.h>
#define MAX_N 1000
#define MOD (unsigned long long)(1e9 + 7)
using namespace std;

int n;
unsigned long long dp[MAX_N + 1];
unsigned long long sum[MAX_N + 1];  // 장식 패턴 누적합

int main(void) {
    cin >> n;

    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;
    sum[0] = dp[0];
    sum[1] = (dp[0] + dp[1]) % MOD;
    sum[2] = (sum[1] + dp[2]) % MOD;

    for (int i = 3; i <= n; i++) {
        dp[i] = (2 * dp[i - 1] + 3 * dp[i - 2] + 2 * sum[i - 3]) % MOD;
        sum[i] = (sum[i - 1] + dp[i]) % MOD;
    }

    cout << dp[n] << "\n";
    
    return 0;
}
