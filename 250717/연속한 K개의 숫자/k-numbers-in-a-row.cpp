#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 1;

int n, k, b;
bool excepted[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> b;

    for (int i = 0; i < b; i++) {
        int num;
        cin >> num;
        excepted[num] = true;
    }

    int missing = 0;
    for (int i = 1; i <= k; i++) {
        if (excepted[i]) missing++;
    }

    int min_missing = missing;
    
    for (int i = k + 1; i <= n; i++) {
        if (excepted[i - k]) missing--;
        if (excepted[i]) missing++;

        min_missing = min(min_missing, missing);
    }

    cout << min_missing << "\n";
    
    return 0;
}
