#include <iostream>
using namespace std;

int main(){
    string f,s;
    cin >> f >> s;
    if(f.size() >= s.size()) cout << "go" << endl;
    else cout << "no" << endl;
    return 0;
}
