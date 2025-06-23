#include <bits/stdc++.h>

#define MAX_N int(1e6)
using namespace std;

int n, k, ans{INT_MAX};
int arr[MAX_N];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int one_cnt{0};
    int s{0}, e{-1};
    for (s = 0; s < n; s++) {

        while (e + 1 < n && one_cnt < k) {
            if (arr[e + 1] == 1) {
                one_cnt++;
            }
            e++;
        }

        if (one_cnt >= k) {
            ans = min(ans, e - s + 1);
        }

        if (arr[s] == 1) {
            one_cnt--;
        }
    }

    if (ans == INT_MAX) {
        ans = -1;
    }
    cout << ans << "\n";

    return 0;
}