#include <bits/stdc++.h>
using ll = long long;
using namespace std;
 
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> initial(n);
        vector<int> final(n);
        for (int i = 0; i < n; i++) cin >> initial[i];
        for (int i = 0; i < n; i++) cin >> final[i];
 
        vector<int> sorted_init = initial;
        vector<int> sorted_fin = final;
        sort(sorted_init.begin(), sorted_init.end());
        sort(sorted_fin.begin(), sorted_fin.end());
 
        bool possible = true;
        for (int i = 0; i < n; i++) {
            if (sorted_init[i] > sorted_fin[i]) {
                possible = false;
                break;
            }
        }
 
        if (!possible) {
            cout << -1 << "
";
            continue;
        }
 
        ll operations = 0;
        for (int i = 0; i < n; i++) {
            int target_b = final[i];
            int best_j = -1;
 
            for (int j = i; j < n; j++) {
                if (initial[j] <= target_b) {
 
                    vector<int> rem_init;
                    for(int k = i; k < n; k++) {
                        if (k != j) rem_init.push_back(initial[k]);
                    }
                    vector<int> rem_fin;
                    for(int k = i + 1; k < n; k++) {
                        rem_fin.push_back(final[k]);
                    }
 
                    sort(rem_init.begin(), rem_init.end());
                    sort(rem_fin.begin(), rem_fin.end());
 
                    bool valid_state = true;
                    for (int k = 0; k < (int)rem_init.size(); k++) {
                        if (rem_init[k] > rem_fin[k]) {
                            valid_state = false;
                            break;
                        }
                    }
 
                    if (valid_state) {
                        best_j = j;
                        break;
                    }
                }
            }
 
            operations += (best_j - i);
            for (int k = best_j; k > i; k--) {
                swap(initial[k], initial[k-1]);
            }
        }
        cout << operations << "
";
    }
    return 0;
}