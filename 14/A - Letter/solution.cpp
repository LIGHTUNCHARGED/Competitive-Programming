//  A. Letter
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, m; cin>>n>>m;
    vector<vector<char>> mat(n, vector<char>(m));
    vector<pair<int, int>> v;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            char c; cin>>c;
            mat[i][j] = c;
            if (c=='*') {
                v.push_back(make_pair(j, i));
            }
        }
    }
    int max_x = INT_MIN, max_y = INT_MIN;
    int min_x = INT_MAX, min_y = INT_MAX;
    for (auto p : v) {
        if (p.first > max_x) max_x = p.first;
        if (p.second > max_y) max_y = p.second;
        if (p.first < min_x) min_x = p.first;
        if (p.second < min_y) min_y = p.second;
    }
    for (int i = min_y; i <= max_y; i++) {
        for (int j = min_x; j <= max_x; j++) {
            cout<<mat[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}