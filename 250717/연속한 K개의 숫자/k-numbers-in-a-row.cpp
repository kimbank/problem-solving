#include <bits/stdc++.h>

#define MAX_N int(1e5 + 1)

using namespace std;

int n, k, b, ans = INT_MAX;
int arr[MAX_N];
int prefix[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> b;

    for (int i = 0; i < b; i++) {
        int num;
        cin >> num;

        arr[num] = 1;
    }

    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    for (int i = 1; i <= n - k + 1; i++) {
        ans = min(ans, prefix[i + k - 1] - prefix[i]);
    }

    cout << ans << "\n";

    return 0;
}
