#include <bits/stdc++.h>

using namespace std;

int n, ans = INT_MIN;
char b[100001];
int l_h[100001], r_h[100001];
int l_s[100001], r_s[100001];
int l_p[100001], r_p[100001];

int calcGame(char a, char b) {
    switch (a) {
        case 'H':
            if (b == 'S')
                return 1;
            break;
        case 'S':
            if (b == 'P')
                return 1;
            break;
        case 'P':
            if (b == 'H')
                return 1;
            break;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    // l
    for (int i = 1; i <= n; i++) {
        // me: 'H'
        l_h[i] = l_h[i - 1] + calcGame('H', b[i]);
        // me: 'S'
        l_s[i] = l_s[i - 1] + calcGame('S', b[i]);
        // me: 'P'
        l_p[i] = l_p[i - 1] + calcGame('P', b[i]);
    }
    // r
    for (int i = n; i >= 1; i--) {
        // me: 'H'
        r_h[i] = r_h[i + 1] + calcGame('H', b[i]);
        // me: 'S'
        r_s[i] = r_s[i + 1] + calcGame('S', b[i]);
        // me: 'P'
        r_p[i] = r_p[i + 1] + calcGame('P', b[i]);
    }


    for (int i = 2; i <= n; i++) {
        // 'H'-'S'
        ans = max(ans, l_h[i - 1] + r_s[i]);
        // 'H'-'P'
        ans = max(ans, l_h[i - 1] + r_p[i]);
        // 'S'-'H'
        ans = max(ans, l_s[i - 1] + r_h[i]);
        // 'S'-'P'
        ans = max(ans, l_s[i - 1] + r_p[i]);
        // 'P'-'H'
        ans = max(ans, l_p[i - 1] + r_h[i]);
        // 'P'-'S'
        ans = max(ans, l_p[i - 1] + r_s[i]);
    }

    cout << ans << "\n";

    return 0;
}
