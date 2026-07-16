//  A. Array Coloring
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int sum = 0;
        for (int i = 0; i < n; i++) {
           int num; cin>>num;
            sum += num;
        }
        sum%2==0 ? cout<<"YES" : cout<<"NO";
        cout<<endl;
    }
    return 0;
}