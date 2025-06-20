#include <bits/stdc++.h>

#define MAX_N int(1e5)

using namespace std;

int n, d;
int ans = INT_MAX;
vector<pair<int,int>> v;
multiset<int> y_values;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> d;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end()); // x 기준 정렬

    int s_idx{0}, e_idx{0};

    for (e_idx = 0; e_idx < n; e_idx++) {
        y_values.insert(v[e_idx].second);

        while (!y_values.empty() && *y_values.rbegin() - *y_values.begin() >= d) {
            ans = min(ans, v[e_idx].first - v[s_idx].first);
            y_values.erase(y_values.find(v[s_idx].second));
            s_idx++;
        }
    }

    if (ans == INT_MAX) {
        ans = -1;
    }

    cout << ans << "\n";

    return 0;
}
