#include <bits/stdc++.h>

#define MAX_N int(1e6)

using namespace std;

int n;
long long ans = LLONG_MAX;
int arr[MAX_N];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n - 1);

    int s{0}, e{n - 1};
    while (s < e) {
        ans = min(ans, (long long)(abs(arr[s] + arr[e])));

        if (arr[s] + arr[e] > 0) {
            e--;
        } else {
            s++;
        }
    }

    cout << ans << "\n";

    return 0;
}
