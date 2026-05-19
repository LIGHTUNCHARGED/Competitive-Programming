#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    vector<int> c(n);
	    vector<int> p(n);
	    for(int i =0; i<n; i++){
	        cin>>c[i];
	        cin>>p[i];
	    }
	    double max_score = 0.0;
	    for(int i = n-1; i>=0; i--){
	        max_score = max(max_score, c[i]+max_score*(1.0 - p[i]/100.0));
	    }
	    cout << fixed << setprecision(10) << max_score << endl;
	}
 
}