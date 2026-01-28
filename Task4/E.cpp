#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0;
    long long currentSum = 0;
    int count = 0;

    for (int r = 0; r < n; r++) {
        currentSum += a[r];

        while (currentSum > x && l <= r) {
            currentSum -= a[l];
            l++;
        }

        if (currentSum == x) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}