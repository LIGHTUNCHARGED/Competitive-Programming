#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    int n, k; cin>>n>>k;
	    vector<int> v(n);
	    for(int i =0; i<n; i++){
	        cin>>v[i];
	    }
	    
	    
	    int min_delta = k;
	    for(int i = 0; i<n; i++){
	        int r = v[i]%k;
	        if(r==0){
	            min_delta=0;
	            break;
	        }else{
	            int delta = k - r;
	            min_delta = min(delta, min_delta);
	        }
	    }
	    if(k==4){
	        int z = 2;
	        for(int i = 0; i<n; i++){
	            int r = v[i]%2;
	            if(z<=0){
	                break;
	            }
	            if(r==0){
	                z--;
	            }
	        }
	        min_delta=min(min_delta, z);
	    }
	    if(min_delta==k){
	        cout<<0<<endl;
	    }else{
	        cout<<min_delta<<endl;
	    }
	}
 
}