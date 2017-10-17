#include <iostream>
#include <math.h>

using namespace std;

int main(){
    double d, a;
    cin >> d >> a;
    if(a >= 0.0 && a <= 180.0) cout << "safe" << endl;
    else if(a > 180.0 && a <= 270.0){
        double deg = 270.0-a;
        double rad = deg*M_PI/180.0;
        cout << floor(d/cos(rad)) << endl;
    } else {
        double deg = a-270.0;
        double rad = deg*M_PI/180.0;
        cout << floor(d/cos(rad)) << endl;
    }
    return 0;
}

