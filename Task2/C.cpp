#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    // These two lines direct the program to read from bcount.in 
    // and write to bcount.out automatically.
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n, q;
    if (cin >> n >> q) {
        vector<int> h(n + 1, 0);
        vector<int> g(n + 1, 0);
        vector<int> j(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int value;
            cin >> value;

            h[i] = h[i - 1];
            g[i] = g[i - 1];
            j[i] = j[i - 1];

            if (value == 1) h[i]++;
            else if (value == 2) g[i]++;
            else if (value == 3) j[i]++;
        }

        for (int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;

            int count1 = h[b] - h[a - 1];
            int count2 = g[b] - g[a - 1];
            int count3 = j[b] - j[a - 1];

            cout << count1 << " " << count2 << " " << count3 << "\n";
        }
    }
    return 0;
}