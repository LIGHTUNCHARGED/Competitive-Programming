#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t; cin>>t;
	while(t--){
	    int n, p; cin>>n>>p;
	    vector<int> a(n);
        vector<int> b(n);
	    for(int i = 0; i<n; i++){
	        cin>>a[i];
	    }
	    for(int i = 0; i<n; i++){
	        cin>>b[i];
	    }
	    vector<int> min_index(n);
	    iota(min_index.begin(), min_index.end(), 0);
	    auto cmp = [&](int x, int y){
	        return b[x]<b[y];
	    };
	    sort(min_index.begin(), min_index.end(), cmp);
	    long long cost = p; 
	    long long count = 1;
	    for(int i = 0; i<n; i++){
	        if(count == n) break;
	        int idx = min_index[i];
	        if(b[idx]<p){
	            long long take = min((long long)a[idx], (long long)(n-count));
	            cost += take * b[idx];
	            count += take;
	        }else{
	            cost += (long long)p * (n-count);
	            count = n;
	            break;
	        }
	    }
	    cout<<cost<<endl;
	        
	}
 
}