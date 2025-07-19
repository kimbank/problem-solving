#include <bits/stdc++.h>

using namespace std;

int ans, n;
vector<tuple<int,int,int>> points;
unordered_set<int> segs;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;

        points.push_back({x1, +1, i});
        points.push_back({x2, -1, i});
    }

    sort(points.begin(), points.end());
    
    for (int i = 0; i < points.size(); i++) {
        auto [x, v, idx] = points[i];

        if (v == +1) {
            if ((int) segs.size() == 0) {
                ans++;
            }

            segs.insert(idx);
        } else {
            segs.erase(idx);
        }
    }

    cout << ans << "\n";

    return 0;
}
