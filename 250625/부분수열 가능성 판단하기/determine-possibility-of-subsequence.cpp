#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    vector<int> prefix(m, -1), suffix(m, -1);

    // 앞에서부터 매칭
    int j = 0;
    for (int i = 0; i < n && j < m; i++) {
        if (a[i] == b[j]) {
            prefix[j] = i;
            j++;
        }
    }

    // 뒤에서부터 매칭
    j = m - 1;
    for (int i = n - 1; i >= 0 && j >= 0; i--) {
        if (a[i] == b[j]) {
            suffix[j] = i;
            j--;
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        bool left_ok = (i == 0 || prefix[i - 1] != -1);
        bool right_ok = (i == m - 1 || suffix[i + 1] != -1);
        bool order_ok = (i == 0 || i == m - 1 || prefix[i - 1] < suffix[i + 1]);

        if (left_ok && right_ok && order_ok) {
            ans++;
        }
    }


    cout << ans << '\n';

    return 0;
}
