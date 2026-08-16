//  A. Forked!
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while (t--) {
        int a, b; cin>>a>>b;
        int xk, yk; cin>>xk>>yk;
        int xq, yq; cin>>xq>>yq;
        int dx[] = {a, -a, a, -a, b, -b, b, -b};
        int dy[] = {b, b, -b, -b, a, a, -a, -a};
        set<pair<int,int>> king, queen;
 
        for (int i = 0; i < 8; i++) {
            king.insert(make_pair(xk + dx[i], yk + dy[i]));
            queen.insert(make_pair(xq + dx[i], yq + dy[i]));
        }
 
        set<pair<int,int>> common;
        set_intersection(king.begin(), king.end(), queen.begin(), queen.end(), inserter(common, common.begin()));
        cout<<common.size()<<endl;
 
    }
    return 0;
}