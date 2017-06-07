#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
    long long int l;
    cin >> l;
    long double ls = sqrt(l);
    cout << setprecision(10) << ls*4 << endl;
    return 0;
}
