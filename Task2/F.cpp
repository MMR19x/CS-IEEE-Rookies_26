#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, q;
    if (cin >> n >> k >> q) {
        const int MAX_VAL = 200000;
        vector<int> diff(MAX_VAL + 2, 0);

        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            diff[l]++;
            diff[r + 1]--;
        }

        vector<int> prefixAdmissible(MAX_VAL + 2, 0);
        int currentRecipeCount = 0;

        for (int i = 1; i <= MAX_VAL; i++) {
            currentRecipeCount += diff[i];
            int isAdmissible = 0;
            if (currentRecipeCount >= k) {
                isAdmissible = 1;
            }
            prefixAdmissible[i] = prefixAdmissible[i - 1] + isAdmissible;
        }

        for (int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;
            cout << prefixAdmissible[b] - prefixAdmissible[a - 1] << "\n";
        }
    }
    return 0;
}