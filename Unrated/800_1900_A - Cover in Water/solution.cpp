#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    string s; cin>>s;
	    int water = 0;
	    for(int i = 0; i<n; i++){
	        if(s[i]=='.'){
    	        if(i > 0 && i < n - 1 && s[i-1] == '.' && s[i] == '.' && s[i+1] == '.'){
    	            water = 2;
    	            break;
    	        }
    	        else{
    	            water += 1;
    	        }
	        }
	    }
	    cout<<water<<endl;
	    
	}
 
}