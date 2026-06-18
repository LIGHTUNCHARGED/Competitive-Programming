//  B. Olya and Game with Arrays
 
#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> min_elements(n);
        vector<int> second_min_elements(n);
        for (int i = 0; i<n; i++) {
            int m; cin>>m;
            int min_element = INT_MAX;
            int second_element = INT_MAX;
            for (int j = 0; j<m; j++) {
                int num; cin>>num;
                if (num<min_element) {
                    second_element = min_element;
                    min_element = num;
                }else if (num < second_element) {
                    second_element = num;
                }
            }
            min_elements[i] = min_element;
            second_min_elements[i] = second_element;
        }
        int min_of_min_elements = *min_element(min_elements.begin(), min_elements.end());
        int min_of_second_min_element_index = 0;
        ll sum_of_second_min_elements = 0;
        for (int i = 0; i<n; i++) {
            if (second_min_elements[min_of_second_min_element_index]>second_min_elements[i]) {
                min_of_second_min_element_index = i;
            }
            sum_of_second_min_elements += second_min_elements[i];
        }
        ll max_beauty = sum_of_second_min_elements - second_min_elements[min_of_second_min_element_index] + min_of_min_elements;
        cout<<max_beauty<<endl;
 
    }
    
    return 0;
}