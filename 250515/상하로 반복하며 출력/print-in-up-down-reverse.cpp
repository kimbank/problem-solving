#include <bits/stdc++.h>

#define MAX_N 9

using namespace std;

int n;

int arr[MAX_N][MAX_N];

int main (int argc, char *argv[]) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 2 == 0) {
                arr[j][i] = j + 1;
            } else {
                arr[j][i] = n - j;
            }
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cout << arr[r][c];
        }
        cout << "\n";
    }
}
