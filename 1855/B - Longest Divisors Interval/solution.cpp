//  B. Longest Divisors Interval
 
#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
 
// if any consecutive integers {s1,s2,s3,...sk} divides n then 1 to k must also divide n.
ll longestConsecutiveDivisor(ll n) {
   ll max_len = 1;
    ll i = 2;
    while (n % i == 0) {
        max_len++;
        i++;
    }
    return max_len;
}
 
int main() {
    int t; cin>>t;
    while (t--){
        ll n; cin>>n;
        cout << longestConsecutiveDivisor(n) << endl;
    }
    return 0;
}