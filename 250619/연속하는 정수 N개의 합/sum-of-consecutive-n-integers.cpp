#include <bits/stdc++.h>

#define MAX_N 100001

using namespace std;

int n, m, ans;
int arr[MAX_N];

int main(void) {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int start_idx = 1;
    int end_idx = 0;
    int acc = 0;
    for (; start_idx <= n; start_idx++) {
        while (end_idx + 1 <= n && acc < m) {
            acc += arr[end_idx + 1];
            end_idx++;
        }

        if (acc == m) {
            ans++;
        }

        acc -= arr[start_idx];
    }

    cout << ans << "\n";
}
