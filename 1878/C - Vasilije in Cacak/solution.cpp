//  C. Vasilije in Cacak
 
#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    int t; cin>>t;
    while(t--) {
        ll n, k, x; cin>>n>>k>>x;
        ll min_x = k*(k+1)/2;
        ll max_x = n*k - k*(k-1)/2;
        x < min_x || x > max_x ? cout<<"NO" : cout<<"YES";
        cout<<endl;
    }
    return 0;
}