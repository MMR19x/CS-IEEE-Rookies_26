#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;
        vector<int> w(n);
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }

        int l = 0;
        int r = n - 1;
        long long A_weight = 0;
        long long B_weight = 0;
        int max_candies = 0;

        while (l <= r) {
            if (A_weight <= B_weight) {
                A_weight += w[l];
                l++;
            } else {
                B_weight += w[r];
                r--;
            }

            if (A_weight == B_weight) {
                max_candies = l + (n - 1 - r);
            }
        }
        cout << max_candies << "\n";
    }
    return 0;
}