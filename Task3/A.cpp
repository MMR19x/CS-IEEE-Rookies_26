#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    if (!(cin >> n >> k)) return 0;

    long long low = 1, high = n;
    long long v = n;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        long long totalLines = 0;
        long long power = 1;

        while (mid / power > 0) {
            totalLines += mid / power;
         
            power *= k;
        }

        if (totalLines >= n) {
            v = mid;        
            high = mid - 1; 
        } else {
            low = mid + 1;  
        }
    }

    cout << v << endl;

    return 0;
}