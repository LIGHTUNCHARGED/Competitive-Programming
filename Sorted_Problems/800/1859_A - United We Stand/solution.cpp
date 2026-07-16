//  A. United We Stand
 
#include<bits/stdc++.h>
 
using namespace std;
 
void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}
 
bool check_all_equal_elements(vector<int> v) {
    if (v.empty()) return true;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != v[0]) return false;
    }
    return true;
}
 
int main() {
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> a;
        int max = INT_MIN;
        for (int i = 0; i < n; i++) {
            int num; cin>>num;
            if (num > max) max = num;
            a.push_back(num);
        }
        if (check_all_equal_elements(a)) {
            cout<<-1<<endl;
            continue;
        }
        vector<int> b;
        vector<int> c;
        for (int i = 0; i < n; i++) {
            if (a[i] == max) {
                c.push_back(a[i]);
            }else {
                b.push_back(a[i]);
            }
        }
        cout<<b.size()<<" "<<c.size()<<endl;
        print_vector(b);
        print_vector(c);
    }
    return 0;
}