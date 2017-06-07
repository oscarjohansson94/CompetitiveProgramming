#include <iostream>

using namespace std;

int main(){
    string in;
    cin >> in;
    if(!in.size())
        return 0;
    int i = 0;
    string res = "";
    if(in[0] == '<') i++;
    for(; i < in.size(); i++){
        if(in[i] == '<'){
            res.erase(res.end()-1);
        }
        else res += in[i];
    }
    if(res.size())
    cout << res << endl;
    return 0;
}
