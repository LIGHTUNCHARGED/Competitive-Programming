#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    string s;
    cin >> s;
    
    int y_count = 0;
    for (char c : s) {
        if (c == 'Y') {
            y_count++;
        }
    }
    
    // If there are 2 or more 'Y's, we can never get rid of them
    if (y_count >= 2) {
        cout << "NO
";
    } else {
        cout << "YES
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