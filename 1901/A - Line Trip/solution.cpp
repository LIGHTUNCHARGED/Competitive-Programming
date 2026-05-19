#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin>>t;
    while(t--){
        int n, x; cin>>n>>x;
        vector<int> stations(n);
        for(int i = 0; i<n; i++){
            cin>>stations[i];
        }
        int max_dist = stations[0];
        for(int i = 0; i<n-1; i++){
            int diff = stations[i+1]-stations[i];
            max_dist = max(max_dist, diff);
        }
        int last_station_dist = 2*(x-stations[n-1]);
        max_dist = max(max_dist, last_station_dist);
        cout<<max_dist<<endl;
    }
}