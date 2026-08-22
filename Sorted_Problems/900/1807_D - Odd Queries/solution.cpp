// okay we have to change all elements in range l to r to k in the array and check if sum of array
// will be odd or not
// okay so we can use prefix sum array in this question I think
// lets try to reverse engineer
//
// 5 5
// 2 2 1 3 2
// 2 3 3
// 2 3 4
// 1 5 5
// 1 4 9
// 2 4 3
//
// now 2 3 3
//
// current_sum = 10, even
//
// sum between 2 and 3 = 2+1 = 3 odd
// even-odd = odd
//
// sum we are replacing = (3-2+1)*3 = 6 even
// odd+even = odd
// so yes sum will be odd
//
// 1 4 9
//
// sum between 1 and 4 = 8 even
//
// sum we are replacing with = 4*9= 36 even
//
// so resulting should be even
//
// so if replace with opposite parity then the parity of total sum changes but if parity we replace with is
// same then total sum parity is same
//
// we can solve it by creating a prefix sum array and find sum we are replacing = pref[r]-pref[l-1] and then
// find it's parity and go ahead that way.
// lets try to implement it
 
 
//  D. Odd Queries
 
#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    int t; cin>>t;
    while(t--) {
        ll n, q; cin>>n>>q;
        vector<ll> prefix_array(n+1, 0);
        for (int i = 1; i <= n; i++) {
            ll num; cin>>num;
            prefix_array[i] = prefix_array[i-1] + num;
        }
        int total_sum = prefix_array[n];
        for(int i=0;i<q;i++) {
            ll l, r, k; cin>>l>>r>>k;
            bool is_odd = false;
            ll query_sum = prefix_array[r] - prefix_array[l-1];
            ll replaced_sum = (r-l+1)*k;
            if ((abs(query_sum - replaced_sum) + total_sum) % 2 != 0) {
                is_odd = true;
            }
            is_odd ? cout<<"YES" : cout<<"NO";
            cout<<endl;
        }
    }
    return 0;
}