#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
   
    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(h.begin(), h.end());
    sort(b.begin(), b.end());

    bool possible = true;
    for (int i = 0; i < k; i++) {
        if (h[i] > b[m - k + i]) {
            possible = false;
            break;
        }
    }

    if (possible) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}