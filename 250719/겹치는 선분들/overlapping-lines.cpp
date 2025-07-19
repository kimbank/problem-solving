#include <bits/stdc++.h>

#define MAX_N int(1e5 + 1)

using namespace std;

int n, k, ans;
vector<tuple<int,int,int>> points;
unordered_set<int> segs;

int arr[MAX_N];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    int cur_idx{0};
    for (int i = 0; i < n; i++) {
        int d; char c;
        cin >> d >> c;

        int nxt_idx;
        if (c == 'R') {
            nxt_idx = cur_idx + d;
            points.push_back({cur_idx, +1, i});
            points.push_back({nxt_idx, -1, i});
        }
        if (c == 'L') {
            nxt_idx = cur_idx - d;
            points.push_back({nxt_idx, +1, i});
            points.push_back({cur_idx, -1, i});
        }

        cur_idx = nxt_idx;
    }

    sort(points.begin(), points.end());

    int prev_segs_size{0}, prev_x{get<0>(points[0])}, prev_p{0};
    int x1{0}, x2{0};
    for (int i = 0; i < points.size(); i++) {
        auto [p, v, idx] = points[i];

        if (v == +1) {
            segs.insert(idx);
        } else {
            segs.erase(idx);
        }

        if (segs.size() >= k) {
            if (prev_segs_size < k) {
                // initial
                x1 = p;
            }
        } else {
            if (prev_segs_size >= k) {
                // terminate
                x2 = p;

                ans += abs(x1 - x2);
            }
        }

        prev_segs_size = segs.size();
        prev_p = p;
    }

    cout << ans << "\n";

    return 0;
}
