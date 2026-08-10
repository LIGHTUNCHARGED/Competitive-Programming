//  D. Good Pair Queries
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while(t--) {
        int n, q; cin>>n>>q;
        string s, t; cin>>s>>t;
        vector<int> p00(n+1, 0), p01(n+1, 0), p10(n+1, 0), p11(n+1, 0);
        for (int i = 0; i < n; i++) {
            p00[i+1]= p00[i] + (s[i]=='0' && t[i]=='0');
            p01[i+1]= p01[i] + (s[i]=='0' && t[i]=='1');
            p10[i+1]= p10[i] + (s[i]=='1' && t[i]=='0');
            p11[i+1]= p11[i] + (s[i]=='1' && t[i]=='1');
        }
 
        for (int i = 0; i < q; i++) {
            int l, r; cin>>l>>r;
 
            int c00 = p00[r] - p00[l-1];
            int c01 = p01[r] - p01[l-1];
            int c10 = p10[r] - p10[l-1];
            int c11 = p11[r] - p11[l-1];
            if (c11+c00>=abs(c10-c01)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        
 
    }
    return 0;
}