#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<long long> v(n + 1);
        vector<long long> u(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            u[i] = v[i];
        }

        sort(u.begin(), u.end());

        vector<long long> prefixV(n + 1, 0);
        vector<long long> prefixU(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefixV[i] = prefixV[i - 1] + v[i];
            prefixU[i] = prefixU[i - 1] + u[i];
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int type, l, r;
            cin >> type >> l >> r;

            long long result;
            if (type == 1)
                result = prefixV[r] - prefixV[l - 1];
            else
                result = prefixU[r] - prefixU[l - 1];

            cout << result << "\n";
        }
    }
    return 0;
}