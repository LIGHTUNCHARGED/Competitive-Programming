//  B. Flipping Binary String
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        string s; cin>>s;
        // now we need to reduce the string to have only one 0. After analyzing the patterns I found out:
        // 1) if no of ones = even then we need to choose all indexes of 1 where no of operations = no of ones
        // 2) if no of zeros = odd then we need to choose all indexes of 0 where no of operations = no of zeros
 
        int zeros = 0; int ones = 0;
        for (char c : s) {
            c == '0' ? zeros++ : ones++;
        }
        if (ones==0) {
            cout<<0<<endl;
            continue;
        }
        if (zeros ==  1) {
            cout<<1<<endl;
            for (int i = 0; i<n; i++) {
                if (s[i] == '0') {
                    cout<<i+1<<endl;
                    break;
                }
            }
            continue;
        }
 
        if (ones%2==0) {
            cout<<ones<<endl;
            for (int i = 0; i < n; i++) {
                if (s[i]=='1') {
                    cout<<i+1<<" ";
                }
            }
        }else if (zeros%2!=0){
            cout<<zeros<<endl;
            for (int i = 0; i < n; i++) {
                if (s[i]=='0') {
                    cout<<i+1<<" ";
                }
            }
        }else {
            cout<<-1;
        }
        cout<<endl;
    }
 
    return 0;
}