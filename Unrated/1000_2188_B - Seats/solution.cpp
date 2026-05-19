#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    // Count the original number of 1s before modifying anything
    int original_ones = 0;
    for (char c : s) {
        if (c == '1') {
            original_ones++;
        }
    }
 
    // Pad the string with "10" at the start and "01" at the end
    // This perfectly simulates the boundary conditions for the edges
    string padded_s = "10" + s + "01";
 
    int added_ones = 0;
    int zero_count = 0;
 
    // Iterate through the padded string to find continuous blocks of '0's
    for (char c : padded_s) {
        if (c == '0') {
            zero_count++;
        } else {
            // When we hit a '1', we process the block of zeroes we just counted
            // For every block of length z, we can add floor(z/3) ones.
            added_ones += (zero_count / 3);
            zero_count = 0; // Reset the counter for the next block
        }
    }
 
    // The total people seated is the original amount plus the new people we can fit
    cout << original_ones + added_ones << "
";
}
 
int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}