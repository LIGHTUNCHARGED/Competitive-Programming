#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t; cin>>t;
	while(t--){
	    int n, m, h; cin>>n>>m>>h;
	    vector<int> arr(n);
	    for(int i = 0; i<n; i++){
	        cin>>arr[i];
	    }
	    vector<int> temp = arr;
	    vector<int> last_reset(n, 0);
	    int current_reset = 0;
	   for(int i = 0; i<m; i++){
	       int b, c; cin>>b>>c;
	       if(last_reset[b-1]<current_reset){
	           temp[b-1] = arr[b-1];
	           last_reset[b-1] = current_reset;
	       }
	       if(temp[b-1]+c<=h){
	           temp[b-1] = temp[b-1]+c;
	       }else{
	           current_reset += 1;
	       }
	   }
	   for(int i = 0; i<n; i++){
	       if(last_reset[i]<current_reset){
	           cout<<arr[i]<<" ";
	       }else{
	           cout<<temp[i]<<" ";
	       }
	   }
	   cout<<endl;
	}
 
}