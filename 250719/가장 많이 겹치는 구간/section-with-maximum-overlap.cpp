#include <bits/stdc++.h>

#define MAX_N int(2e5 + 1)

using namespace std;

int n, s, e, ans;
int points[MAX_N];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;

        s = min(s, x1);
        e = max(e, x2);

        points[x1]++;
        points[x2]--;
    }

    int acc{0};
    for (int i = s; i <= e; i++) {
        acc += points[i];

        ans = max(ans, acc);
    }

    cout << ans << "\n";

    return 0;
}
