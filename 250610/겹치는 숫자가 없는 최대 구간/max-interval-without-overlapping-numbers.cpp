#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

int n, ans = 0;
int arr[MAX_N + 1];
bool cnt[MAX_N + 1];

int main(int argc, char* argv[]) {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int j = 0;
    for (int i = 1; i <= n; i++) {
        while (j + 1 <= n && !cnt[arr[j + 1]]) {
            cnt[arr[j + 1]] = true;
            j++;
        }

        ans = max(ans, j - i + 1);

        cnt[arr[i]] = false;
    }

    cout << ans << "\n";
}