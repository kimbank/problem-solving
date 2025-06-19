#include <bits/stdc++.h>

#define INF int(1e9)
#define MAX_N int(1e6)

using namespace std;

int n, ans = INF;
int arr[MAX_N];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int s{0}, e{n - 1};
    while(s < e) {
        ans = min(ans, abs(arr[s] + arr[e]));

        if (arr[s] + arr[e] > 0) {
            e--;
        } else {
            s++;
        }
    }

    cout << ans << "\n";

    return 0;
}