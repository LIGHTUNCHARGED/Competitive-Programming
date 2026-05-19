#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    int zeros = 0;
	    int ones = 0;
	    for(int i = 0; i<n; i++){
	        int num; cin>>num;
	        if(num==0){
	            zeros+=1;
	        }
	        if(num==1){
	            ones += 1;
	        }
	    }
	    if((zeros && ones) || (zeros == 1)){
	        cout<<"YES"<<endl;
	    }else{
	        cout<<"NO"<<endl;
	    }
	}
 
}