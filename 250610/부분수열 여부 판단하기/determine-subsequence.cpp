#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

int n, m;
bool flag = true;
int a[MAX_N+1];
int b[MAX_N+1];

int main(int argc, char* argv[]) {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    int i = 1;
    for (int j = 1; j <= m; j++) {
        while (i <= n && a[i] != b[j]) {
            i++;
        }

        if (i == n + 1) {
            flag = false;
        } else {
            i++;
        }
    }

    if (flag) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
