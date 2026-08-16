//  A. Extremely Round
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while (t--) {
        string s; cin>>s;
        int extremely_round=0;
        for (int i = 0; i<s.size(); i++) {
            if (i == 0) {
                extremely_round += s[i]-'0';
            }else {
                extremely_round += 9;
            }
        }
        cout << extremely_round << endl;
    }
    return 0;
}