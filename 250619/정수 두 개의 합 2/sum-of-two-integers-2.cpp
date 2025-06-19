#include <bits/stdc++.h>

#define MAX_N 100001

using namespace std;

int n, k, ans;
int arr[MAX_N];

int main(void) {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + n);

    int s = 1;
    int e = 1;
    int s_item = arr[s];
    for (;s <= n; s++) {
        s_item = arr[s];
        // e = s;

        while (e + 1 <= n && s_item + arr[e + 1] <= k) {
            ans++;
            e++;
        }
    }

    cout << ans << "\n";

    return 0;
}
