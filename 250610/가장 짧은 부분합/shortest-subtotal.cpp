#include <bits/stdc++.h>

#define INF int(1e9)
#define MAX_N 100001

using namespace std;

int n, s, ans = INF;
int arr[MAX_N];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s;

    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    for (int i = 1; i <= n; i++) {
        int cur_sum = 0, j = i;

        while (cur_sum < s && j <= n && j-i < ans) {
            cur_sum += arr[j];
            j++;
        }

        if (cur_sum >= s) {
            ans = min(ans, j-i);
        }
    }

    if (ans == INF) {
        cout << -1 << "\n";
        return 0;
    }
    cout << ans << "\n";
}
