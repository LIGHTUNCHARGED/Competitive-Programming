//  A. One and Two
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> prefix(n, 0);
        for (int i = 0; i < n; i++) {
            int num; cin>>num;
            int count = (num==2 ? 1 : 0);
            if (i==0) {
                prefix[i] = count;
            }else {
                prefix[i] = prefix[i-1] + count;
            }
        }
        int ans = -1;
        for (int i = 0; i < n-1; i++) {
            int right_twos = prefix[i];
            int left_twos = prefix[n-1] - prefix[i];
            if (right_twos == left_twos) {
                ans = i+1;
                break;
            }
        }
        cout<<ans<<endl;
 
    }
    return 0;
}