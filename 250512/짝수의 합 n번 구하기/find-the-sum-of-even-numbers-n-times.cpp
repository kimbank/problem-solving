#include <bits/stdc++.h>

using namespace std;

int calc (int a, int b) {
    int ret = 0;
    for (int i = a; i <= b; i++) {
        if (i % 2 == 0) {
            ret += i;
        }
    }
    return ret;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << calc(a, b) << "\n";
    }
}