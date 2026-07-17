//  D. An Alternative Way
 
#include<bits/stdc++.h>
 
using namespace std;
using vll = long long;
int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<vll> a(n);
        vector<vll> b(n);
        for (int i = 0; i < n; i++) cin>>a[i];
        for (int i = 0; i < n; i++) cin>>b[i];
        vll prefix_sum = 0;
        bool possible = true;
        for (int i  = 0; i<n; i++) {
            vll diff = b[i]-a[i];
            prefix_sum += diff;
            if (prefix_sum < 0) {
                possible = false;
            }
        }
        possible ? cout<<"YES" : cout<<"NO";
        cout<<endl;
    }
    return 0;
}