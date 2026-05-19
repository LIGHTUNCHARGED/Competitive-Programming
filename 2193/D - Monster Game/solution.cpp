#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t; 
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        
        vector<long long> str(n);
        for(int i = 0; i < n; i++) {
            cin >> str[i];
        }
        
        vector<long long> lvl(n);
        for(int i = 0; i < n; i++) {
            cin >> lvl[i];
        }
        
        
        sort(str.begin(), str.end());
        
        vector<long long> pref(n + 1, 0);
        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + lvl[i];
        }
        
        long long max_score = 0;
        
        for(int i = 0; i < n; i++) {
            long long x = str[i];
            long long usable_swords = n - i;
            
            int lvl_cleared = upper_bound(pref.begin(), pref.end(), usable_swords) - pref.begin() - 1;
            
            long long score = lvl_cleared * x;
            
            if(score > max_score) {
                max_score = score;
            }
        }
        cout << max_score << "
";
    }
    return 0;
}