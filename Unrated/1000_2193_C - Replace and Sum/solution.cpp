#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t; cin>>t;
	while(t--){
	    int n, q; cin>>n>>q;
	    vector<int> a(n);
	    vector<int> b(n);
	    for(int i = 0; i<n ; i++){
	        cin>>a[i];
	    }
	    for(int i = 0; i<n ; i++){
	        cin>>b[i];
	    }
	    for(int i = 0; i<n ; i++){
	        if(a[i]<b[i]){
	            a[i] = b[i];
	        }
	    }
	    for(int i = n-2; i>=0 ; i--){
	        if(a[i]<a[i+1]){
	            a[i] = a[i+1];
	        }
	    }
	    vector<int> prefix_sum(n+1);
	    for(int i = 0; i<n; i++){
	        prefix_sum[i+1] = prefix_sum[i] + a[i];
	    }
	    
	    for(int i = 0; i<q; i++){
	        int l, r; 
	        cin>>l>>r;
	        int sum = prefix_sum[r] - prefix_sum[l-1];
	        cout<<sum<<" ";
	    }
	   
	        
	    
	    cout<<endl;
	}
 
}