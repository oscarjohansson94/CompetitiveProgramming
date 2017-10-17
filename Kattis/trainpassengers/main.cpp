#include <iostream>

using namespace std;

int main() {
    int c = 0, n = 0;
    cin >> c >> n;
    int p = 0;
    bool done = false;
    for(int i = 0; i < n;i++){
        int a,l,s;
        cin >> l >> a >> s;
        p -= l;
        if(p < 0) {
            done = true;
            cout << "impossible" << endl;
            break;
        }
        p += a;
        if(p > c){
            done = true;
            cout << "impossible" << endl;
            break;
        }
        if(s && p != c){
            done = true;

            cout << "impossible" << endl;
            break;
        }

    }
    if(!done && p) {
        cout << "impossible" << endl;
        return 0;
    }
    if(!done)
    cout << "possible" << endl;
    return 0;
}