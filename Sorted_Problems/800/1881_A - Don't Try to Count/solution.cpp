#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int t; cin >> t;
    while (t--) 
    {
        int n, m; 
        cin >> n >> m;
        string x, s; 
        cin >> x >> s;
 
        int ops = 0;
        bool found = false;
 
        while (ops <= 6) 
        {
            // string::npos is not found
            if (x.find(s) != string::npos) 
            {
                found = true;
                break;
            }
            x += x;
            ops++;
        }
 
        if (found) {
            cout << ops << "
";
        } else {
            cout << -1 << "
";
        }
    }
    return 0;
}