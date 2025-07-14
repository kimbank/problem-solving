#include <bits/stdc++.h>

#define MAX_N 502

using namespace std;

int n, k, ans;
int grid[MAX_N][MAX_N];
int prefix[MAX_N][MAX_N];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;

    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            cin >> grid[r][c];
            prefix[r][c] = prefix[r - 1][c] +
                            prefix[r][c - 1] -
                            prefix[r - 1][c - 1] +
                            grid[r][c];
        }
    }

    for (int r = k; r <= n; r++) {
        for (int c = k; c <= n; c++) {
            int total = prefix[r][c] -
                        prefix[r - k][c] -
                        prefix[r][c - k] +
                        prefix[r - k][c - k];
            ans = max(ans, total);
        }
    }

    cout << ans << "\n";
    
    return 0;
}
