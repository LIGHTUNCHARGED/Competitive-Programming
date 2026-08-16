//  A. Everybody Likes Good Arrays!
 
#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            cin>>v[i];
        }
        int same_parity = 0;
        for (int i = 0; i < n-1; i++) {
            if ((v[i]+v[i+1]) % 2 == 0) {
                same_parity++;
            }
        }
        cout<<same_parity<<endl;
    }
    return 0;
}