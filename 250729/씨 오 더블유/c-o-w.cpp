#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string word;
    cin >> n >> word;

    long long cntC = 0, cntO = 0, cntW = 0;

    for (char ch : word) {
        if (ch == 'C') cntC++;
        else if (ch == 'O') cntO += cntC;
        else if (ch == 'W') cntW += cntO;
    }

    cout << cntW << "\n";
    return 0;
}
