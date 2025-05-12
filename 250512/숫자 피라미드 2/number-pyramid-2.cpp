#include <iostream>
using namespace std;

int main() {
    int n, k = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << (++k) << " ";
        }
        cout << "\n";
    }
    return 0;
}