//  A. Desorting
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }
        int min_diff = INT_MAX;
        for (int i = 1; i < n; i++) {
            if (a[i]-a[i-1] < min_diff) {
                min_diff = a[i]-a[i-1];
            }
        }
        min_diff < 0 ? cout<<0 : cout<<(min_diff/2)+1;
        cout<<endl;
 
    }
    return 0;
}