#include <bits/stdc++.h>

#define MAX_N 1001

using namespace std;

int n, ans;
long long k, prefix[MAX_N];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i - 1];

        for (int j = 0; j < i; j++) {
            if (prefix[i] - prefix[j] == k) {
                ans++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
