#include <bits/stdc++.h>

#define MAX_N 1000
#define MOD (unsigned long long)(1e9 + 7)

using namespace std;

int n, ans;
unsigned long long dp[MAX_N + 1];

int main(void) {
    cin >> n;

    dp[0] = 1UL;
    dp[1] = 2UL;
    // dp[2] = 7UL;
    for (int i = 2; i < n + 1; i++) {
        dp[i] = ((2 * dp[i - 1]) + (((i % 2 == 0) ? 3 : 4) * dp[i - 2])) % MOD;
    }

    cout << dp[n] << "\n";

    return 0;
}