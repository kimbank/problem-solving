#include <bits/stdc++.h>

#define MAX_N 4

using namespace std;

int arr[MAX_N][MAX_N];

int main(void) {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            int tmp;
            cin >> tmp;

            if (j <= i) {
                arr[i][j] = tmp;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < MAX_N; i++) {
        ans += accumulate(arr[i], arr[i] + MAX_N, 0);
    }

    cout << ans << "\n";
}