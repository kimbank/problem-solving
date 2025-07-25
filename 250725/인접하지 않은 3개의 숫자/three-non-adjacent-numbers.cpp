#include <bits/stdc++.h>

using namespace std;

int n, ans;
int arr[100000];
int dp[100001][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0][1] = arr[0]; dp[1][1] = arr[0];
    dp[2][2] = arr[2];
    dp[4][3] = arr[4];
    for (int i = 3; i < n; i++) {
        dp[i][1] = max(dp[i-1][1], arr[i]);
        dp[i][2] = max(dp[i-1][2], dp[i-2][1] + arr[i]);
        dp[i][3] = max(dp[i-1][3], dp[i-2][2] + arr[i]);
    }

    cout << dp[n - 1][3] << "\n";

    return 0;
}
