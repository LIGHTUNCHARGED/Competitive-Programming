//  A. Doremy's Paint 3
 
#include<bits/stdc++.h>
 
using namespace std;
 
 
int main() {
    int t; cin>>t;
    while (t--) {
        // b1 + b2 = b2 + b3 +.... = k
        // b1 = b3 = b5 = ...., b2 = b4 = b6 =...
        // so at most 2 distinct numbers are allowed
        // 1 number then always True
        // 2 distinct number then they must alternate x,y,x,y,x,y,...... for that they must have frequency difference atmost 1
        int n; cin>>n;
        map<int,int> freq;
        for (int i=0;i<n;i++) {
            int num; cin>>num;
            freq[num]++;
        }
        if (freq.size()>2) {
            cout<<"No"<<endl;
        }else if (freq.size()==1) {
            cout<<"Yes"<<endl;
        }else {
            auto it = freq.begin();
            int freq_first = (*it).second;
            it++;
            int freq_second = (*it).second;
            int diff = abs(freq_first - freq_second);
            if (diff<=1) {
                cout<<"Yes"<<endl;
            }else {
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}