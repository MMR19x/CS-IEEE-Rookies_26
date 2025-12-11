#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    if (cin >> n >> q) {
        vector<long long> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int value;
            cin >> value;
            prefix[i] = prefix[i - 1] + value;
        }

        for (int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;
            long long sum = prefix[b] - prefix[a - 1];
            cout << sum << "\n";
        }
    }
    return 0;
}