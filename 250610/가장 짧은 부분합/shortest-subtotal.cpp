#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int start = 0, end = 0, sum = 0;
    int ans = INT_MAX;

    while (true) {
        if (sum >= s) {
            ans = min(ans, end - start);
            sum -= arr[start++];
        } else if (end == n) break;
        else {
            sum += arr[end++];
        }
    }

    if (ans == INT_MAX) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}
