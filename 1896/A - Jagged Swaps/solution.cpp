//  A. Jagged Swaps
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> numbers(n);
        for (int i = 0; i < n; i++) {
            cin>>numbers[i];
        }
        // Since first number cannot be swapped it must always be 1 then only it can be sorted
        numbers[0] != 1 ? cout<<"NO" : cout<<"YES";
        cout<<endl;
 
    }
 
    return 0;
}