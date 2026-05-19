#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    if (n == 0) {
            cout << 0 << endl;
            continue;
        }
	    vector<int> a(n);
	    for(int i = 0; i<n; i++){
	            cin>>a[i];
	    }
	    
	    int max_ele = a[0];
	    for(int i = 0; i<n; i++){
	       max_ele = max(max_ele, a[i]);
	    }
	    int sum = max_ele*n;
	    cout<<sum<<endl;
	    
	}
 
}