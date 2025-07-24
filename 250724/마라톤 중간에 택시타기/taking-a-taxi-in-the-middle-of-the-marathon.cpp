#include <bits/stdc++.h>

using namespace std;

int n, ans = INT_MAX;
int x[100001], y[100001];
int l[100001], r[100001];

int calcDist(int sx, int sy, int dx, int dy) {
    return abs(dx - sx) + abs(dy - sy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    // l
    l[1] = 0;
    for (int i = 2; i < n; i++) {
        l[i] = l[i - 1] + calcDist(x[i], y[i], x[i - 1], y[i - 1]);
    }
    // r
    r[n] = 0;
    for (int i = n - 1; i >= 1; i--) {
        r[i] = r[i + 1] + calcDist(x[i + 1], y[i + 1], x[i], y[i]);
    }

    // finding
    for (int i = 2; i < n; i++) {
        ans = min(ans, l[i - 1] + r[i + 1] + calcDist(x[i-1], y[i-1], x[i+1], y[i+1]));
    }

    cout << ans << "\n";

    return 0;
}
