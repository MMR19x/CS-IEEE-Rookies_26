#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<int> p(n);
    vector<int> pref(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pref[i + 1] = pref[i] ^ p[i];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        
        int answer = pref[b] ^ pref[a - 1];
        cout << answer << "\n";
    }

    return 0;
}