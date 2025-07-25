#include <bits/stdc++.h>
using namespace std;

int n, ans;
int arr[100000];
int lmax[100000];
int rmax[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 왼쪽 누적 최대값
    lmax[0] = arr[0];
    for (int i = 1; i < n; i++) {
        lmax[i] = max(lmax[i - 1], arr[i]);
    }

    // 오른쪽 누적 최대값
    rmax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rmax[i] = max(rmax[i + 1], arr[i]);
    }

    // 가운데 수를 기준으로 좌우 떨어진 최대값 합 계산
    for (int j = 2; j <= n - 3; j++) {
        int left = lmax[j - 2];
        int right = rmax[j + 2];
        ans = max(ans, arr[j] + left + right);
    }

    cout << ans << "\n";
    
    return 0;
}
