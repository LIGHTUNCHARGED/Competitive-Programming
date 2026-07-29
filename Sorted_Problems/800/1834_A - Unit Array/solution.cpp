//  A. Unit Array
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        int sum = 0;
        int num_negatives = 0;
        for (int i = 0; i < n; i++) {
            int num; cin>>num;
            sum += num;
            if (num < 0) num_negatives++;
        }
        int ops = 0;
        while (sum < 0) {
            sum += 2;
            num_negatives--;
            ops++;
        }
 
        if (num_negatives%2 != 0 ) {
            ops++;
        }
        cout<<ops<<endl;
 
    }
    return 0;
}