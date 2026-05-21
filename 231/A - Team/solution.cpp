//  A. Team
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n; cin>>n;
    int problems = 0;
    for (int i = 0; i<n; i++) {
        int P,V,T; cin>>P>>V>>T;
        // Solve the boolean function using K-map (F=VT+VP+PT) to detect the problem they will solve
        (V && T || V&&P || P&&T == 1) ? problems++ : NULL;
    }
    cout<<problems;
    return 0;
}