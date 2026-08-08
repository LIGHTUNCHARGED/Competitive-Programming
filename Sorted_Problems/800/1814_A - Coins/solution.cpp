//  A. Coins
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    int t; cin>>t;
    while(t--) {
        ll n, k; cin>>n>>k;
        (k == 1 || (k % 2 == 1) || (k % 2 == 0 && n % 2 == 0)) ? cout<<"YES" : cout<<"NO";
         cout<<'
';
    }
 
    return 0;
}