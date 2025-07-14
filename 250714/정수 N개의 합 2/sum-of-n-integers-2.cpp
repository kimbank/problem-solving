#include <bits/stdc++.h>

#define MAX_N int(1e5)

using namespace std;

int n, k, ans = INT_MIN;
int acc[MAX_N + 1];

int main(void) {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> acc[i];
        acc[i] += acc[i - 1];
    }

    for (int i = k; i <= n; i++) {
        ans = max(ans, acc[i] - acc[i - k]);
    }

    cout << ans << "\n";

    return 0;
}
