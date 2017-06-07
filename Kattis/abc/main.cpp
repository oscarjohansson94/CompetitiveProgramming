#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v(3);
    for(int i = 0; i < 3; i++) 
        cin >> v[i];
    sort(begin(v),end(v));
    int a = v[0], b = v[1], c = v[2];
    string order = "";
    cin >> order;
    bool first = true;
    for(char ch : order){
        if(first){
            first = false;
        } else {
            cout << " ";
        }
        if(ch == 'A') cout << a;
        if(ch == 'B') cout << b;
        if(ch == 'C') cout << c;
    }
    return 0;
}
