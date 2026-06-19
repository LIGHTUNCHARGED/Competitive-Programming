//  C. Target Practice
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin>>t;
    while (t--) {
        // The score is minimum distance from x or y from the edges
        // score_indexes = min(min(r, 9-r), min(c, 9-c))
        // ring 1 = distance from edges = 0
        // ring 2 = distance from edges = 1
        // ring 5 = distance from edges = 4
        // we get indexes then we access from scores
        int scores[5] = {1,2,3,4,5};
        int total_score = 0;
        for (int r = 0; r < 10; r++) {
            for (int c = 0; c < 10; c++) {
                char ch; cin>>ch;
                if (ch == 'X') {
                    int dist_x = min(r, 9-r);
                    int dist_y = min(c, 9-c);
                    int score = min(dist_x, dist_y);
                    total_score += scores[score];
                }
            }
        }
        cout<<total_score<<endl;
    }
    return 0;
}