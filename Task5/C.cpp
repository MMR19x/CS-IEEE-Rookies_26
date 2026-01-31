#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
long long solve(int i, const vector<int>& a, long long sum1, long long sum2, int n) {
    if (i == n) {
        return abs(sum1 - sum2);
    }

    long long choose1 = solve(i + 1, a, sum1 + a[i], sum2, n);
    
    long long choose2 = solve(i + 1, a, sum1, sum2 + a[i], n);

    return min(choose1, choose2);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << solve(0, p, 0, 0, n) << endl;

    return 0;
}