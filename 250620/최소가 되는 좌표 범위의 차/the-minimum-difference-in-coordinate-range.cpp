#include <bits/stdc++.h>

#define MAX_N int(1e5)

using namespace std;

int n, d;
int ans = INT_MAX;
vector<pair<int,int>> v;

int main(void) {
    cin >> n >> d;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
        // v.push_back({y, x});
    }

    sort(v.begin(), v.end());

    // int s_idx{0}, e_idx{n - 1};
    // while (s_idx < e_idx) {

    //     if (abs(s_y - e_y) >= d) {
    //         ans = min(ans, abs(e_x - ));
    //     }
    // }
    int s{0}, e{0};
    for (s = 0; s < n; s++) {
        auto [s_x, s_y] = v[s];
        auto [e_x, e_y] = v[e];

        while (e + 1 < n && abs(s_y - e_y) < d) {
            auto [e_x, e_y] = v[e + 1];
        }

        if (abs(s_y - e_y) >= d) {
            ans = min(ans, abs(e_x - s_x));
        }
    }

    if (ans == INT_MAX) {
        ans = -1;
    }
    cout << ans << "\n";

    return 0;
}