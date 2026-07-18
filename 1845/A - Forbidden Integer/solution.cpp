//  A. Forbidden Integer
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while(t--) {
        int n, k, x; cin>>n>>k>>x;
        if (x==1) {
            if (k==1) {
                cout<<"NO"<<endl;
                continue;
            }
            if (n%2==0){
                cout<<"YES"<<endl;
                int number_of_two = n/2;
                cout<<number_of_two<<endl;
                for (int i = 0; i<number_of_two; i++) {
                    cout<<2<<" ";
                }
                cout<<endl;
                continue;
            }else {
                if (k==2) {
                    cout<<"NO"<<endl;
                    continue;
                }else if (k>=3) {
                    cout<<"YES"<<endl;
                    int number_of_two = (n-3)/2;
                    cout<<number_of_two+1<<endl;
                    cout<<3<<" ";
                    for (int i = 0; i<number_of_two; i++) {
                        cout<<2<<" ";
                    }
                    cout<<endl;
                }
 
            }
        }else {
            cout<<"YES"<<endl;
            cout<<n<<endl;
            for (int i = 0; i<n; i++) {
                cout<<1<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}