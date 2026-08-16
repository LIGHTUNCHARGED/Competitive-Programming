//  A. Make it Beautiful
 
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
        // since a[0]<=a[1]...,<=a[n-1], all equal case
        if (v[0] == v[n-1]) {
            cout<<"NO"<<endl;
            continue;
        }else {
            cout<<"YES"<<endl;
        }
        // max, min, second min, third min, ..... .2nd max
        cout<<v[n-1]<<" ";
        for (int i = 0; i < n-1; i++) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
 
    }
    return 0;
}