#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> count(7);
    vector<int> index(7);
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int in;
        cin >> in;
        count[in]++;
        index[in] = i;
    }
    bool found = false;
    for(int i = 6; i >= 1; i--){
        if(count[i] == 1){
            found = true;
            cout << index[i] + 1 << endl;
            break;
        }}
    if(!found) cout << "none" << endl;
    return 0;
}
