//  A. We Need the Zero
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int xor_sum = 0;
        for (int i = 0; i < n; i++) {
            int x; cin>>x;
            xor_sum ^= x;
        }
        if (n%2==0) {
            xor_sum != 0 ? cout<<-1 : cout<<0;
        } else {
            cout<<xor_sum;
        }
        cout<<endl;
    }
    return 0;
}