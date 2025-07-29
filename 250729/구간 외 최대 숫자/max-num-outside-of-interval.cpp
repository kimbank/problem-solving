#include <bits/stdc++.h>

#define MAX_N int(1e5+2)

using namespace std;

int n, q;
int nums[MAX_N];
int L[MAX_N], R[MAX_N];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    // L
    for (int i = 1; i <= n; i++) {
        L[i] = max(L[i - 1], nums[i]);
    }

    // R
    for (int i = n; i > 0; i--) {
        R[i] = max(R[i + 1], nums[i]);
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        cout << max(L[a - 1], R[b + 1]) << "\n";
    }

    return 0;
}