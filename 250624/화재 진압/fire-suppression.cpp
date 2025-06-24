#include <bits/stdc++.h>

using namespace std;

int n, m;
long long ans;
vector<long long> fires, stations;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int f;
        cin >> f;
        fires.push_back(f);
    }

    for (int i = 0; i < m; i++) {
        int s;
        cin >> s;
        stations.push_back(s);
    }

    sort(fires.begin(), fires.end());
    sort(stations.begin(), stations.end());

    int s{0}, f{0};
    for (f = 0; f < n; f++) {

        while (s + 1 < m &&
            llabs(fires[f] - stations[s + 1]) <= llabs(fires[f] - stations[s])
            ) {
                s++;
        }
        
        ans = max(ans, llabs(fires[f] - stations[s]));
    }
    
    cout << ans << "\n";

    return 0;
}