#include <iostream>

using namespace std;

int main(){
    int a,b;
    while(cin >> a >> b && (a || b)){
        if(a+b == 13)
            cout << "Never speak again." << endl;
        else if(a == b)
            cout << "Undecided." << endl;
        else if(a > b)
            cout << "To the convention." << endl;
        else
            cout << "Left beehind." << endl;
    }
    return 0;
}
