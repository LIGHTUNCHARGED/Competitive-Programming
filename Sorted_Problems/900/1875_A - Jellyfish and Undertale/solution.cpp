//  A. Jellyfish and Undertale
 
#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int t; cin>>t;
    while(t--) {
        ll a, b, n; cin>>a>>b>>n;
        ll tt = b;
        for(int i=0; i<n; i++) {
            ll x; cin>>x;
            tt += min(1+x, a)-1;
        }
        cout<<tt<<endl;
 
    }
    return 0;
}
 
 