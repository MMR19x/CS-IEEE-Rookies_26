#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int l = 0, r = n - 1;
    int A_time = 0, B_time = 0;
    int A_count = 0, B_count = 0;

    while (l <= r) {
        if (A_time <= B_time) {
            A_time += t[l];
            l++;
            A_count++;
        } 
        else {
            B_time += t[r];
            r--;
            B_count++;
        }
    }

    cout << A_count << " " << B_count << endl;

    return 0;
}