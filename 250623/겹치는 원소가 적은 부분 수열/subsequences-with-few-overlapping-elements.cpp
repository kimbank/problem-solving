#include <bits/stdc++.h>

#define MAX_N int(1e5)

using namespace std;

int n, k, ans, cnt;
int arr[MAX_N];
unordered_map<int, int> um;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        um[arr[i]] = 0;
    }

    int s{0}, e{0};
    for (e = 0; e < n; e++) {
        um[arr[e]]++;

        while (um[arr[e]] > k) {
            um[arr[s]]--;
            s++;
        }

        ans = max(ans, e - s + 1);
    }

    cout << ans << "\n";

    return 0;
}