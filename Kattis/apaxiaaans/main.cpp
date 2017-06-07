#include <iostream>
using namespace std;

int main() {
    string s = "";
    cin >> s;
    char last = '@';
    for(int i = 0; i < s.size(); i++){
       if(s[i] == last){}
       else{
            last = s[i];
            cout << s[i];
       }
    }
    cout << endl;
    return 0;
}
