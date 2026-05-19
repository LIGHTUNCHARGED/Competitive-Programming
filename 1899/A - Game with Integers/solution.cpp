//  A. Game with Integers
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        n%3==0 ? cout<<"Second" : cout<<"First";
        cout<<endl;
    }
    return 0;
}