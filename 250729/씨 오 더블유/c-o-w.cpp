#include <bits/stdc++.h>

#define MAX_N int(1e5+1)

using namespace std;

int n;
long long ans;
string word;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> word;

    /** Solution 1: Codetree */
    // L: 'C'
    int L[MAX_N];
    L[0] = 0;
    for (int i = 0; i < n; i++) {
        if (word[i] == 'C') {
            L[i + 1] = L[i] + 1;
        } else {
            L[i + 1] = L[i];
        }
    }

    // R: 'W'
    int R[MAX_N];
    R[n] = 0;
    for (int i = n - 1; i > 0; i--) {
        if (word[i] == 'W') {
            R[i] = R[i + 1] + 1;
        } else {
            R[i] = R[i + 1];
        }
    }

    // find ans
    for (int i = 0; i <= n; i++) {
        // cout << "L: " << L[i] << " R:" << R[i] << endl;
        if (word[i] == 'O') {
            ans += L[i + 1] * R[i + 1];
        }
    }

    cout << ans << "\n";

    /** Solution 2 */
    // long long cntC = 0, cntO = 0, cntW = 0;

    // for (char ch : word) {
    //     if (ch == 'C') cntC++;
    //     else if (ch == 'O') cntO += cntC;
    //     else if (ch == 'W') cntW += cntO;
    // }

    // cout << cntW << "\n";

    return 0;
}
