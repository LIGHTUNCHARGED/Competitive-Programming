//  B. Blank Space
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin>>v[i];
        }
        int max_op = 0;
        for (int i = 0; i < n; i++) {
            if (v[i]==0) {
                int ops = 0;
                while (i<n && v[i]==0) {
                    ops++;
                    i++;
                }
                max_op = max(max_op, ops);
            }
        }
        cout<<max_op<<endl;
    }
    return 0;
}