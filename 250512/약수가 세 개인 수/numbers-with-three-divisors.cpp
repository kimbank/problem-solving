#include <bits/stdc++.h>

using namespace std;

int countDivisor(int num) {
    int cnt = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int ans = 0, start, end;
    cin >> start >> end;

    for (int i = start; i <= end; i++) {
        if (countDivisor(i) == 3) {
            ans++;
        }
    }

    cout << ans << "\n";
}