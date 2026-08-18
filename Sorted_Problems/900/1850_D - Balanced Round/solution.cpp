//  D. Balanced Round
 
#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;
int main() {
    int t; cin>>t;
    while(t--) {
        ll n, k; cin>>n>>k;
        vector<ll> v(n);
        for(ll i=0; i<n; i++) {
            cin>>v[i];
        }
        sort(v.begin(), v.end());
        ll max_length = 1;
        ll current_length = 1;
        for(ll i=0; i<n-1; i++) {
            if (v[i+1]-v[i]<=k) {
                current_length++;
                max_length = max(max_length, current_length);
            } else {
                current_length = 1;
            }
        }
        cout<<n-max_length<<endl;
    }
    return 0;
}