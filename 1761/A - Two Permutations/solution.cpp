//  A. Two Permutations
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while(t--) {
        int n, a, b; cin>>n>>a>>b;
        if (n == a && a == b) {
            cout << "Yes
";
        } else if (a + b + 2 <= n) {
            cout << "Yes
";
        } else {
            cout << "No
";
        }
 
    }
    
    return 0;
}