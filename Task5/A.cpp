#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        int xor_sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            xor_sum ^= a[i];
        }

        for (int i = 0; i < n; i++) {
            if ((xor_sum ^ a[i]) == a[i]) {
                cout << a[i] << "\n";
                break; 
            }
        }
    }

    return 0;
}