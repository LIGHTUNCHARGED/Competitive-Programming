//  B. Square Pool
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while (t--) {
        int n, s; cin>>n>>s;
        int pockets = 0;
        for (int i = 0; i < n; i++) {
            int dx, dy, xi, yi; cin>>dx>>dy>>xi>>yi;
            
            // The balls should lie on straight line y=x at angle 45 or -45 or on straight line y=s-x at angle +135 or -135
            
            if ((xi==yi && (dx==1 && dy==1 || dx==-1 && dy==-1)) || (yi==s-xi && (dx==1 && dy==-1 || dx==-1 && dy==1))) {
                pockets++;
            }
        }
        cout<<pockets<<endl;
    }
 
    return 0;
}