#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    if (cin >> t) {
        for (int i = 0; i < t; i++) {
            int n, q;
            cin >> n >> q;
            vector<long long> prefix(n + 1, 0);

            for (int o = 1; o <= n; o++) {
                int value;
                cin >> value;
                prefix[o] = prefix[o - 1] + value;
            }
            long long totalsum = prefix[n];

            for (int j = 0; j < q; j++) {
                int l, r;
                long long k;
                cin >> l >> r >> k;

                long long oldrange = prefix[r] - prefix[l - 1];
                long long newrange = (r - l + 1) * k;
                long long finalsum = totalsum - oldrange + newrange;

                if (finalsum % 2 == 0)
                    cout << "NO\n";
                else
                    cout << "YES\n";
            }
        }
    }
    return 0;
}