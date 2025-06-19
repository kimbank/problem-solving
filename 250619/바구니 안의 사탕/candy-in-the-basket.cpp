#include <bits/stdc++.h>

#define MAX_ARR int(1e6 + 1)
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

    int s;
    int e = -1;
    int acc{0};
    int max_width = k * 2;
    for (s = 0; s <= max_idx; s++) {
        while (e + 1 <= max_idx && e - s <= max_width) {
            acc += arr[e + 1];
            e++;
        }

        ans = max(ans, acc);
        acc -= arr[s];
    }

    cout << ans << "\n";

    return 0;
}