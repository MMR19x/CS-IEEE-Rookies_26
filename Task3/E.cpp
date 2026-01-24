#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int d = 0;
    int tower = 0;

    for (int i = 0; i < n; i++) {
        while (tower + 1 < m &&
               abs(b[tower + 1] - a[i]) <= abs(b[tower] - a[i])) {
            tower++;
        }
        
        int curr_dist = abs(b[tower] - a[i]);
        d = max(d, curr_dist);
    }

    cout << d << endl;

    return 0;
}