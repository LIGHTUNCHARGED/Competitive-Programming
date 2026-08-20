// we have to choose a constant k
// such that i-j = k
// then swap pi and pj
//
// we need to find max value of k
//
// lets try to reverse engineer
//
// 3
// 3 1 2
// swap(1,3) k=1
// 1 3 2
// swap (2,3) k=1
// 1 2 3
// max_k = 1
// we could have done different operations also to get k = 2
// but we need to minimize swaps also i think
//
// 4
// 3 4 1 2
// swap(1,3) k=2
// 1 4 3 2
// swap(4,2) k=2
// 1 2 3 4
// max_k = 2
//
// 9
// 1 6 7 4 9 2 3 8 5
// okay lets think differently lets try to find how far actual number is from it's position
// 1 ok
// 6 no, 2 is 6-2=4 places away
// so k =4
// 7 no, 3 is 7-3=4 places away so k =4
// 4 ok
// 9 no, k=9-5=4
// 2 no, k=abs(2-6) = 4
// 3 no, k=abs(3-7) = 4
// 8 ok
// 5 no, k=abs(5-9)=4
// max_k = 4
//
// so k = abs(current_num-current_position)
// max_k = max(k, max_k)
//
// 6
// 1 5 3 4 2 6
//
// 1 ok
// 5 no abs(5-2) = 3
// 3 ok
// 4 ok
// 2 no abs(2-5) = 3
// 6 ok
// max_k = 3
//
// 3
// 3 1 2
//
// 3 no, abs(3-1) = 2
// wait k_max = 1 for this
// but we are getting 2 by this approach
// so there is something wrong
// I think k = abs(current_index - current_index of number which should be on this index)
// now
//
// 3 no, 1 should be there so
// k = abs(1-2) = 1 (1 currently at index 2)
// now swap also
// 1 3 2
// again check 3 no so abs(2-3) = 1
// so max_k = 1
//
// 11
// 1 11 6 4 8 3 7 5 9 10 2
//
// 1 ok
// 11 no, k = abs(2-11) = 8 wait
// but max_k = 3 for this
// I am wrong somewhere
//
// wait k must be constant for all values so we must choose a k which is valid for all values
//
// 10
// 3 10 5 2 9 6 7 8 1 4
//
// 3 no, k = 2
// 10 no, k = 10-2=8
// 5 no, k = 2
// 2 no, k = 2
// 9 no, k = 4
// 6 ok
// 7 ok
// 8 ok
// 1 no k = 8
// 4 no k = 6
//
// now k can only take 1 value we need to choose k so that it valid for all jumps
//
// max_k = gcd(k1,k2,k3,k4,...)
// as a number can take multiple jumps to reach it's position also
//
// so max_k = gcd(2, 8, 2, 2, 4, 2, 6) = 2
//
// okay this should work
// lets try to implement it
 
//  B. Permutation Swap
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin>>v[i];
        }
        vector<int> k;
        for (int i = 0; i < n; i++) {
            if (v[i] != i+1) {
                int temp_k = abs(v[i]-i-1);
                k.push_back(temp_k);
            }
        }
        int max_k = k[0];
        for (int i = 1; i < k.size(); i++) {
            max_k = gcd(max_k, k[i]);
        }
        cout << max_k << endl;
    }
    return 0;
}