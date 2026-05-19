#include <bits/stdc++.h>
using namespace std;
 
void solve(int k, bool is_sorted) {
    if(is_sorted){
        cout<<"YES"<<endl;
    }else{
        if(k==1){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    cin >> t;
    while (t--) {
        int n,k; cin>>n>>k;
        bool is_sorted = true;
        int previous; 
        if(n>0){
            cin>>previous;
        }
        for(int i = 1; i<n; i++){
            int current; cin>>current;
            if(previous>current){
                is_sorted = false;
            }
            previous = current;
        }
        solve(k, is_sorted);
    }
    return 0;
}