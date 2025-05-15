#include <bits/stdc++.h>

using namespace std;

int n;

int main () {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 2 == 0)
                cout << j+1;
            else
                cout << (n - j);
        }
        cout << "\n";
    }
}