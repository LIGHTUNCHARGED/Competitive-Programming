//  A. Koshary
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while (t--) {
        int x, y; cin>>x>>y;
        (x%2!=0) && (y%2!=0) ? cout<<"NO" : cout<<"YES";
        cout<<endl;
    }
    
    return 0;
}