#include <bits/stdc++.h>

#define MAX_N 1001
#define MOD 10007

using namespace std;

int n;
int dp[MAX_N];

int main(void) {
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i < n + 1; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]*2) % MOD;
    }

    cout << dp[n] << "\n";

    return 0;
}