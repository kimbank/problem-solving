#include <bits/stdc++.h>

#define MAX_N int(1e5)

using namespace std;

int n, ans;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    vector<tuple<int,int,int>> points(n * 2);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        points.push_back({a, +1, i});
        points.push_back({b, -1, i});
    }

    sort(points.begin(), points.end());

    int s{INT_MAX}, e{INT_MIN};
    unordered_set<int> idxs;
    for (auto p : points) {
        auto [x, v, idx] = p;

        if (v == +1) {
            idxs.insert(idx);
            s = min(s, x);
        }
        if (v == -1) {
            idxs.erase(idx);
            e = max(e, x);

            if (idxs.size() == 0) {
                // cout << idx << ": " << s << ", " << e << endl;
                ans += abs(e - s);
                s = INT_MAX;
                e = INT_MIN;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
