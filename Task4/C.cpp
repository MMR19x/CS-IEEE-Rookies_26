#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    vector<int> a(n);
    vector<int> totalFreq(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        totalFreq[a[i]]++;
    }

    vector<int> limit(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (totalFreq[i] > 0) {
            if (totalFreq[i] % k != 0) {
                cout << 0 << "\n";
                return;
            }
            limit[i] = totalFreq[i] / k;
        }
    }

    long long awesomeCount = 0;
    vector<int> windowFreq(n + 1, 0);
    int l = 0;

    for (int r = 0; r < n; r++) {
        int val = a[r];
        windowFreq[val]++;

        while (windowFreq[val] > limit[val]) {
            windowFreq[a[l]]--;
            l++;
        }

        awesomeCount += (r - l + 1);
    }

    cout << awesomeCount << "\n";
}

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}