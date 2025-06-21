#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    vector<int> max_group_until(n, 0);
    int s = 0;
    for (int e = 0; e < n; e++) {
        while (v[e] - v[s] > k) s++;
        int group_len = e - s + 1;
        max_group_until[e] = (e == 0 ? group_len : max(max_group_until[e - 1], group_len));
    }

    vector<int> max_group_from(n, 0);
    int e = n - 1;
    for (int s = n - 1; s >= 0; s--) {
        while (v[e] - v[s] > k) e--;
        int group_len = e - s + 1;
        max_group_from[s] = (s == n - 1 ? group_len : max(max_group_from[s + 1], group_len));
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, max_group_until[i] + max_group_from[i + 1]);
    }
    ans = max(ans, max_group_until[n - 1]); // 한 그룹만 썼을 경우

    cout << ans << '\n';
    
    return 0;
}
