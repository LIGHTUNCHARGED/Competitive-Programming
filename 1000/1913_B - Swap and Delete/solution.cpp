#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t; cin>>t;
	while(t--){
	    string s; cin>>s;
	    string sc;
	    //Find the compelement
	    int ones = 0;
	    int zeros = 0;
	    for(char c: s){
	        
	        if(c=='1'){
	            sc.push_back('0');
	            ones += 1;
	        }else{
	            sc.push_back('1');
	            zeros+=1;
	        }
	    }
	    if(zeros==ones){
	        cout<<0<<endl;
	        continue;
	    }
	    for(int i = 0; i<s.size(); i++){
	        if(s[i]=='1'){
	            if(zeros>0){
	                zeros-=1;
	            }else{
	                cout<<s.size()-i<<endl;
	                break;
	            }
	        }
	        if(s[i]=='0'){
	            if(ones>0){
	                ones-=1;
	            }else{
	                cout<<s.size()-i<<endl;
	                break;
	            }
	        }
	    }
	    
	}
	return 0;
}