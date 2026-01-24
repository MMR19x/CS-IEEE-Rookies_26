#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    int q;
    cin >> q;

    while (q--) {
        int m;
        cin >> m;

        int low = 0;
        int high = n - 1;
        int count = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (x[mid] <= m) {
                count = mid + 1;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << count << "\n";
    }

    return 0;
}