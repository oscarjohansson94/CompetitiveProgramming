#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>


using namespace std;

long count(long n) {
  int result = 0;
  while (n != 0) {
    result += ((n%10) == 0);
    n /= 10;
  }
  return result;
}

long cnt(unsigned n) {
  if (n < 10) return 0;

  if ((n % 10) != 9) return count(n) + cnt(n-1);

  return 10*cnt(n/10) + (n/10);
}


int main() {
    long long start, end;
    while(true){
        cin >> start >> end;
        if(start == -1 && end == -1) break;
        long res = 0;
        if(start != 0){
            cout <<  cnt(end) - cnt(start-1) << endl;
        } else {
            cout << cnt(end) + 1 << endl;
        }
    }

    return 0;
}
