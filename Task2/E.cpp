#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> preGCD(n);
        vector<int> sufGCD(n);

        preGCD[0] = a[0];
        for (int i = 1; i < n; i++) {
            preGCD[i] = gcd(preGCD[i - 1], a[i]);
        }

        sufGCD[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            sufGCD[i] = gcd(sufGCD[i + 1], a[i]);
        }

        int maxResult = 0;

        for (int i = 0; i < n; i++) {
            int currentGCD;

            if (i == 0) {
                currentGCD = sufGCD[1];
            } else if (i == n - 1) {
                currentGCD = preGCD[n - 2];
            } else {
                currentGCD = gcd(preGCD[i - 1], sufGCD[i + 1]);
            }

            if (currentGCD > maxResult) {
                maxResult = currentGCD;
            }
        }

        cout << maxResult << "\n";
    }
    return 0;
}