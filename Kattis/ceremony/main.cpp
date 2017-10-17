#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main() {
    int delta = 0;
    int n = 0;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    sort(begin(h),end(h));
    int best = n;
    for(int i = 0; i < n; i++)
        best = min(h[i] + n - (i  + 1), best);
    cout << best << endl;
    return 0;
}