//  C. Traffic Light
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        char c; cin>>c;
        string s; cin>>s;
        string new_s  = s + s;
        if (c == 'g') {
            cout<<0<<endl;
            continue;
        }
        int max_dist = 0;
        for (int i = 0; i<n; i++) {
            if (s[i] == c) {
                int j = i;
                while (new_s[j] != 'g') {
                    j++;
                }
                if (j - i > max_dist) {
                    max_dist = j - i;
                }
                i = j;
            }
        }
        cout<<max_dist<<endl;
    }
    return 0;
}