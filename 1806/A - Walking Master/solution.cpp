//  A. Walking Master
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while (t--) {
        int a, b, c, d; cin>>a>>b>>c>>d;
        if ((d-b)<0 || c-a>d-b) {
            cout<<-1<<'
';
            continue;
        }else {
            cout<<2*abs(b-d) + a - c<<'
';
            continue;
        }
    }
    return 0;
}