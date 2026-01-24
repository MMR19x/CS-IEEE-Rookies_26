#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    long long low = 1;
    long long high = (long long)t[0] * k;
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long products = 0;

        for (int i = 0; i < n; i++) {
            products += (mid / t[i]);
            if (products >= k) break;
        }

        if (products >= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}