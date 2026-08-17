//  A. Make It Zero
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        int total_xor = 0;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
           int x; cin>>x;
            v[i] = x;
            total_xor ^= x;
        }
        if (n%2==0) {
            cout<<2<<endl;
            cout<<1<<" "<<n<<endl;
            cout<<1<<" "<<n<<endl;
            continue;
        }
        if (total_xor==0) {
            cout<<1<<endl;
            cout<<1<<" "<<n<<endl;
            continue;
        }
        int select_xor = 0;
        for (int i = 0; i<n-1; i++) {
            select_xor ^= v[i];
        }
        if (select_xor != 0) {
            cout<<4<<endl;
            cout<<1<<" "<<n-1<<endl;
            cout<<1<<" "<<n-1<<endl;
            cout<<n-1<<" "<<n<<endl;
            cout<<n-1<<" "<<n<<endl;
        }else {
            cout<<3<<endl;
            cout<<1<<" "<<n-1<<endl;
            cout<<n-1<<" "<<n<<endl;
            cout<<n-1<<" "<<n<<endl;
        }
 
    }
    return 0;
}