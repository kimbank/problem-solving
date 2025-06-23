#include <bits/stdc++.h>

#define MAX_N int(1e5)

using namespace std;

int n, k, ans, cnt;
int arr[MAX_N];
unordered_map<int, int> um;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        um[arr[i]] = 0;
    }

    int s{0}, e{-1};
    for (s = 0; s < n; s++) {
        while (e + 1 < n && um[arr[e + 1]] < k) {
            ans = max(ans, ++cnt);
            um[arr[e + 1]]++;
            e++;
        }

        if (arr[s] >= 0) {
            arr[s]--;

            if (arr[s] == 0) {
                --cnt;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}