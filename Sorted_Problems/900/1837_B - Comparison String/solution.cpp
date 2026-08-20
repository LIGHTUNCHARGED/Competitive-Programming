// okay
// for 13,37,42,37,13
// the string is <<>>
// cost = number of unique elements in array
// we are give the string
// and we need to calculate minimum cost which is possible
//
// for n char string we will have n+1 numbers in array
//
// okay lets try to reverse engineer
//
// 4
// <<>>
// so lets try to make a sample array from it
// 1 2 3 2 1
// so min_cost = 3
// I notice that the highest element is when <> comes
//
// 4
// >><<
// 5 4 3 4 5
// min_cost = 3
//
// min element when >< comes
//
// 5
// >>>>>
// 5 4 3 2 1 0
// okay
// so if there is only one type > or < then answer is simply n+1
//
// 7
// <><><><
//
// 1 10 1 10 1 10 1 10
//
// min_cost = 2
//
// okay
//
// so lets say
// 5
// <><<<
// 1 3 1 3 4 5
// min_cost = 4
// okay so <> reduced cost from 6 to 4
// so each <> reduce by 2?
// <><><><
// min_cost is 2 reduced from 8
// and there are 3 <><><> so 8-6 =2
// okay
// same should be true for ><
// 4
// >><<
// we have one >< so reduce max_cost-2 = 5-2=3
// okay works
// so we just need to count number of
// <> and >< patterns
// min_cost = n+1 - 2*max(count_<>, count_><)
//
// lets try to implement it
//
// //  B. Comparison String
//
// #include<bits/stdc++.h>
//
// using namespace std;
//
// int main() {
//     int t; cin>>t;
//     while(t--) {
//         int n; cin>>n;
//         string s; cin>>s;
//         int count_1 = 0;
//         int count_2 = 0;
//         for (int i = 0; i < n-1; i++) {
//             if (s[i]=='<' && s[i+1]=='>') {
//                 count_1++;
//             }else if (s[i]=='>' && s[i+1]=='<') {
//                 count_2++;
//             }
//         }
//         int min_cost = n+1 - 2*max(count_1, count_2);
//         cout<<min_cost<<endl;
//     }
//     return 0;
// }
//
// okay this is wrong!
//
// s = "<<<<>>>>"
//
// min_cost = 9-2 = 7
// but answer is 5
//
// s = "<><><><><><><><><><>"
// min_cost = 21-20 =1
// which is not possible
// okay
//
// if we have k consecutive identical < or > then we need k+1 elements
//
// so our task is to find maximum consecutive identical elements l
// and then min_cost = k+1
//
// let's implement this
 
//  B. Comparison String
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        string s; cin>>s;
        int k_max = 1;
        int k_current = 1;
        for (int i = 0; i < n-1; i++) {
            if (s[i]==s[i+1]) {
                k_current++;
                k_max = max(k_max, k_current);
            } else {
                k_current = 1;
            }
        }
        int min_cost = k_max + 1;
        cout<<min_cost<<endl;
    }
    return 0;
}
 
 