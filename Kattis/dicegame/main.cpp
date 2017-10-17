#include <iostream>
#include <math.h>

using namespace std;


bool are_same(double a, double b){
    return fabs(a-b) < 0.0000000000001;
}

int main() {
    double g1 = 0, g2 = 0, g3 = 0, g4 = 0, e1 = 0, e2 = 0, e3 = 0, e4 = 0;
    cin >> g1 >> g2 >> g3 >> g4 >> e1 >> e2 >> e3 >> e4;
    double g = (g1+g2)/2.0 + (g3+g4)/2;
    double e = (e1+e2)/2 + (e3+e4)/2;
    if(are_same(e,g)) cout << "Tie" << endl;
    else if(e < g) cout << "Gunnar" << endl;
    else cout << "Emma" << endl;


    return 0;
}
