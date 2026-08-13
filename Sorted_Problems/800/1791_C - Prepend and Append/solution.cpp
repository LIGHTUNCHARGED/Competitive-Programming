//  C. Prepend and Append
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        string v; cin>>v;
        int length = n;
        int left = 0;
        int right = n-1;
       while (right>left) {
           if (v[left] == v[right]) {
               break;
           }else {
               length-=2;
               left++;
               right--;
           }
       }
        cout<<length<<endl;
 
    }
    return 0;
}