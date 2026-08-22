//  B. Not Dividing
 
#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    int t; cin>>t;
    while (t--) {
        ll n; cin>>n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin>>v[i];
            if (v[i] == 1) {
                v[i] = 2;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (v[i + 1] % v[i] == 0) {
                v[i + 1]++;
            }
        }
 
        for (int i =0; i<n; i++) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}