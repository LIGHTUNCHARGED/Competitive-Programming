//  A. Serval and Mocha's Array
 
#include<bits/stdc++.h>
 
using namespace std;
 
 
int main() {
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin>>v[i];
        }
        bool should_break = false;
        bool possible = false;
        for (int i = 0; i < n && !should_break; i++) {
            for (int j = i + 1; j < n; j++) {
                if (gcd(v[i], v[j]) <=2) {
                    possible = true;
                    should_break = true;
                    break;
                }
            }
        }
        possible ? cout<<"YES" : cout<<"NO";
        cout<<endl;
        
    }
    return 0;
}