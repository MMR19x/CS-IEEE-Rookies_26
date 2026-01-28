#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    long long t; 
    if (!(cin >> n >> t)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0;
    long long current_sum = 0;
    int max_books = 0;

    for (int r = 0; r < n; r++) {
        current_sum += a[r];

        while (current_sum > t && l <= r) {
            current_sum -= a[l];
            l++;
        }

        max_books = max(max_books, r - l + 1);
    }

    cout << max_books << endl;

    return 0;
}