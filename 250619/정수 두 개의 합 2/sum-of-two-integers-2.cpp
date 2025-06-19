#include <bits/stdc++.h>

#define MAX_N 100001

using namespace std;

int n, k, ans;
int arr[MAX_N];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int s = 0;
    int e = n - 1;

    while (s < e) {
        if (arr[s] + arr[e] <= k) {
            ans += (e - s);
            s++;
        } else {
            e--;
        }
    }

    cout << ans << "\n";

    return 0;
}
