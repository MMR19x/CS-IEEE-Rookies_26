#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    int s = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s ^= a[i];
    }

    for (int i = 0; i < n; i++) {
        int answer = s ^ a[i];
        cout << answer << "\n";
    }

    return 0;
}