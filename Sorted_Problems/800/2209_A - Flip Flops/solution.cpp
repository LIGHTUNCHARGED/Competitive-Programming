//  A. Flip Flops
 
#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int t; cin>>t;
    while (t--) {
        ll n,c,k; cin>>n>>c>>k;
        vector<ll> power(n);
        for (int i = 0; i<n; i++) {
            cin>>power[i];
        }
        sort(power.begin(), power.end());
        for (int i = 0; i<n; i++) {
            if (power[i]<=c) {
                if (c>=power[i]+k) {
                    c += power[i]+k;
                    k = 0;
                }else {
                    k = k - c + power[i];
                    c += c;
                }
            }else {
                break;
            }
        }
        cout<<c<<endl;
    }
 
    return 0;
}