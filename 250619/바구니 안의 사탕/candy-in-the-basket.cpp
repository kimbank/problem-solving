#include <bits/stdc++.h>

#define MAX_ARR int(1e6) + 1
using namespace std;

int n, k, ans;
int max_idx;
int arr[MAX_ARR];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0 ; i < n; i++) {
        int cnt, idx;
        cin >> cnt >> idx;
        arr[idx] += cnt;
        max_idx = max(max_idx, idx);
    }

    int s = 0, e = 0;
    int acc = arr[0];
    int max_width = 2 * k + 1;

    while (e <= max_idx) {
        ans = max(ans, acc);

        if (e - s + 1 < max_width && e + 1 <= max_idx) {
            e++;
            acc += arr[e];
        } else {
            acc -= arr[s];
            s++;
            if (s > e && s <= max_idx) {
                e = s;
                acc = arr[s];
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
