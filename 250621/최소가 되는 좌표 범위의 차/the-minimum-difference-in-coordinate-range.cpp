#include <bits/stdc++.h>

#define MAX_N int(1e5)

using namespace std;

int n, d;
int ans = INT_MAX;
vector<pair<int,int>> v;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> d;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        // v.push_back({x, y});
        v.push_back({y, x});
    }

    sort(v.begin(), v.end());

    int s_idx{0}, e_idx{0};
    for (s_idx = 0; s_idx < n - 1; s_idx++) {
        e_idx = s_idx +1;
        auto [s_x, s_y] = v[s_idx];
        auto [e_x, e_y] = v[e_idx];

        while (e_idx + 1 < n && abs(s_y - v[e_idx].second) < d) {
            e_idx++;
        }

        if (abs(s_y - v[e_idx].second) >= d) {
            ans = min(ans, abs(v[e_idx].first - s_x));
        }
    }

    if (ans == INT_MAX) {
        ans = -1;
    }
    cout << ans << "\n";

    return 0;
}