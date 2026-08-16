//  B. Chemistry
 
#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin>>t;
    while(t--) {
        int n,k; cin>>n>>k;
        string s; cin>>s;
        if (n-k==1) {
            cout<<"YES"<<endl;
            continue;
        }
        int hash[26] = {};
        for(int i=0; i<n; i++) {
            hash[s[i]-'a']++;
        }
        int odds = 0; int evens = 0;
        for(int i=0; i<26; i++) {
            hash[i]%2==0 ? evens++ : odds++;
        }
        (odds-k<=1) ? cout<<"YES" : cout<<"NO";
        cout<<endl;
 
    }
    
    return 0;
}