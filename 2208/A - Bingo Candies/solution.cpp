#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    map<int, int> m;
	    for(int i = 0; i<n; i++){
	        for(int j = 0; j<n; j++){
	            int num; cin>>num;
	            m[num]++;
	        }
	    }
	    int max_freq = 0; 
	    for(auto p : m){
	        if(p.second>max_freq){
	            max_freq = p.second;
	        }
	    }
	    
	    if(max_freq<=(n*(n-1))){
	        cout<<"YES"<<endl;
	    }else{
	        cout<<"NO"<<endl;
	    }
	    
	}
 
}