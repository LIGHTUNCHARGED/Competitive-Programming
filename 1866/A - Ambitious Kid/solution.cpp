//  A. Ambitious Kid
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n; cin>>n;
    int abs_minimum = INT_MAX;
    for (int i = 0; i < n; i++) {
        int num; cin>>num;
        if (abs(num) < abs_minimum) {
            abs_minimum = abs(num);
        }
    }
    cout<<abs_minimum<<endl;
    return 0;
}