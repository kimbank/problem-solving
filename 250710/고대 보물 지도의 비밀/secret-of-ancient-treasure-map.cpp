#include <bits/stdc++.h>

#define MAX_N 100001

using namespace std;

int n, k;
long long ans = LLONG_MIN;
int arr[MAX_N];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left{0}, right{0}, cur_k{0};
    long long cur_sum{0};
    for (; right < n; right++) {
        cur_sum += arr[right];
        if (arr[right] < 0) {
            cur_k++;
        }

        while (left <= right && cur_k > k) {
            cur_sum -= arr[left];
            if (arr[left] < 0) {
                cur_k--;
            }
            left++;
        }

        ans = max(ans, cur_sum);
    }

    cout << ans << "\n";

    return 0;
}
