#include <iostream>
 
using namespace std;
 
void solve() {
    long long x, y;
    cin >> x >> y;
    
    bool possible = true;
    
    // 1. Check boundary conditions based on the sign of Y
    if (y >= 0) {
        if (x < 2 * y) {
            possible = false;
        }
    } else {
        if (x < -4 * y) {
            possible = false;
        }
    }
    
    // 2. Check modulo condition (safe from negative modulo issues here)
    if (possible) {
        if ((x - 2 * y) % 3 != 0) {
            possible = false;
        }
    }
    
    // 3. Output result
    if (possible) {
        cout << "YES
";
    } else {
        cout << "NO
";
    }
}
 
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}