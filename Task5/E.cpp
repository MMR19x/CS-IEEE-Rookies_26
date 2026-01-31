#include "bits/stdc++.h"

#define ll long long
#define vi vector< int >
#define vll vector< ll >
#define all(x) x.begin(),x.end()
#define endl '\n'

using namespace std;

void solve() {
    ll a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0 << endl;
        return;
    }

    auto get_MSB = [](ll n) -> ll {
        if (n == 0) return 0;
        return 1LL << (63 - __builtin_clzll(n));
    };

    ll msbA = get_MSB(a);
    ll msbB = get_MSB(b);

    if (msbB > msbA) {
        cout << -1 << endl;
        return;
    }

    ll mask = msbA * 2 - 1;
    ll operations = a ^ mask;
    ll x = b ^ mask;

    cout << 2 << endl;
    cout << operations << " " << x << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();
}