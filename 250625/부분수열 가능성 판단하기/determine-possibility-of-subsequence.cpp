#include <bits/stdc++.h>

#define MAX_NM int(1e5)

using namespace std;

int n, m, ans;
int a[MAX_NM], b[MAX_NM];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < m; i++) {
        vector<int> cur;
        for (int j = 0; j < m; j++) {
            if (j != i) {
                cur.push_back(b[j]);
            } 
        }

        vector<bool> visited(cur.size(), false);
        int s{0}, e{0};
        for (e = 0; e < cur.size(); e++) {
            
            while (s + 1 < n && a[s] != cur[e]) {
                s++;
            }
            
            if (a[s] == cur[e]) {
                visited[e] = true;
            }
        }

        ans++;
        for (auto k : visited) {
            if (!k) {
                ans--;
                break;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
