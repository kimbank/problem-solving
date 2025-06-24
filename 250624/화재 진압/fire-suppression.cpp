#include <bits/stdc++.h>

#define MAX_NM int(1e5)

using namespace std;

int n, m;
int fires[MAX_NM];
int stations[MAX_NM];
int dists[MAX_NM];

int main(void) {
    cin >> n >> m;

    // init dists
    for (int i = 0; i < n; i++) {
        dists[i] = INT_MAX;
    }

    for (int i = 0; i < n; i++) {
        cin >> fires[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> stations[i];
    }

    int f{0}, s{-1};
    for (f = 0; f < n; f++) {
        
        while (s + 1 < m && abs(fires[f] - stations[s + 1]) < dists[f]) {
            dists[f] = abs(fires[f] - stations[s+1]);
            s++;
        }
    }

    int ans{0};
    for (int i = 0; i < n; i++) {
        if (dists[i] != INT_MAX)
            ans = max(ans, dists[i]);
        else
            ans = max(ans, abs(fires[i] - stations[m - 1]));
    }
    cout << ans << "\n";

    return 0;
}