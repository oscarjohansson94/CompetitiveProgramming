#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n,m;
    while( cin >> n >> m && !(!n&&!m)){
        vector<int> heads(n);
        vector<int> knights(m);
        for(int i = 0; i < n; i++){
            cin >> heads[i];
        }
        for(int i = 0; i < m; i++){
            cin >> knights[i];
        }
        sort(begin(heads),end(heads));
        sort(begin(knights),end(knights));
        int i = 0, j = 0;
        int res = 0;
        while(i < heads.size() && j < knights.size()){
            if(heads[i] <= knights[j]){
                res += knights[j];
                i++;
                j++;
            } else{
                j++;
            }
        }
        if(i == heads.size()) cout << res << endl;
        else cout << "Loowater is doomed!" << endl;
    }
    return 0;
}

