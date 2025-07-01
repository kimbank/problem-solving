#include <bits/stdc++.h>

#define MAX_N int(1e5)
#define MAX_K 10

using namespace std;

int n, k;
long long ans = INT_MIN;
long long arr[MAX_N + 1];
long long dp[MAX_N + 1][MAX_K + 1];

bool inRange(int r, int c) {
    return r >= 0 && r <= n && c >= 0 && c <= k;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int r = 0; r <= n; r++) {
        for (int c = 0; c <= k; c++) {
            dp[r][c] = INT_MIN;
        }
    }

    if (arr[1] < 0) {
        dp[1][1] = arr[1];
        ans = dp[1][1];
    } else {
        dp[1][0] = arr[1];
        ans = dp[1][0];
    }
    for (int r = 2; r <= n; r++) {
        for (int c = 0; c <= k; c++) {
            // 바로 윗칸
            if (arr[r] >= 0) {
                if (inRange(r - 1, c)) {
                    dp[r][c] = max(arr[r], arr[r] + dp[r - 1][c]);
                }
            } else { // 바로 윗쪽 왼쪽칸 
                if (inRange(r - 1, c - 1)) {
                    dp[r][c] = max(arr[r], arr[r] + dp[r - 1][c - 1]);
                }
            }

            ans = max(ans, dp[r][c]);
        }
    }

    cout << ans << "\n";

    return 0;
}
