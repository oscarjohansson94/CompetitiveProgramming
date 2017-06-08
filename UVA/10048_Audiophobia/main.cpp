#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    bool first = false;
    int c = 0, s = 0, q = 0;
    int cases = 1;
    int default_v = 100000;
    cin >> c >> s >> q;
    while(c || s || q){
        unordered_map<int, map<int, int>> values;
        for(int i  = 1; i <= c; i++) {
            for (int j = 1; j <= c; j++) {
                if(i != j){
                    values[i][j] = default_v;
                }
            }
        }
        for(int i = 0; i < s; i++){
            int c1 = 0 , c2 = 0, d = 0;
            cin >> c1 >> c2 >> d;
            values[c1][c2] = d;
            values[c2][c1] = d;
        }
        if(first){
            cout << endl;
        }
        else{
            first = true;
        }
        cout << "Case #" << cases << endl;
        // Floyd-Warshall for all paths 
        for(int k = 1; k <= c; k++){
            for(int i = 1; i <= c; i++){
                for(int j = 1; j <= c; j++){
                    if(values[i][j] > max(values[i][k], values[k][j])){
                        values[i][j] = max(values[i][k], values[k][j]);
                        values[j][i] = max(values[i][k], values[k][j]);
                    }
                }
            }
        }
        for(int i = 0 ; i < q; i++){
            int c1 = 0, c2 = 0;
            cin >> c1 >> c2;
            int val = values[c1][c2];
            if (val == default_v){
                cout << "no path" << endl;
            }else{
                cout << val << endl;
            }
        }

        cases++;
        cin >> c >> s >> q;
    }

    return 0;
}
