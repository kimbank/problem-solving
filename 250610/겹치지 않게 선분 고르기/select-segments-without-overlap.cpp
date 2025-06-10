#include <bits/stdc++.h>

#define MAX_N 1001

using namespace std;

int n, ans;
bool visited[MAX_N];
vector<pair<int,int>> v;

void fill_arr(int l, int r, bool item) {
    for (int i = l; i <= r; i++) {
        visited[i] = item;
    }
}

bool is_available(int l, int r) {
    for (int i = l; i <= r; i++) {
        if (visited[i]) return false;
    }
    return true;
}

void find(int idx, int cnt) {
    if (idx == n) {
        ans = max(ans, cnt);
        return;
    }

    auto [l, r] = v[idx];

    if (is_available(l, r)) {
        fill_arr(l, r, true);
        find(idx + 1, cnt + 1);
        fill_arr(l, r, false);
    }
    
    find(idx+1, cnt);
}

int main(int argc, char *argv[]) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        v.push_back({l,r});
    }

    find(0, 0);

    cout << ans << "\n";
}
