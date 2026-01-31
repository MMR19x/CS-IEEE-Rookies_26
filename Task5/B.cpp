#include <iostream>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    long long answer = 1;
    int mod = 1000000007;

    for (int i = 0; i < n; i++) {
        answer = (answer * 2) % mod;
    }

    cout << answer << endl;

    return 0;
}