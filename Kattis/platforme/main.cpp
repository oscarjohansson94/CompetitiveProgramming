#include <iostream>
#include <vector>

using namespace std;

struct Platform{
    int y,x1,x2;
};

int MAX_V = 1000000;

int main(){
    int n = 0;
    cin >> n;
    vector<Platform> plats(n);
    int y,x1,x2;
    for(int i = 0; i < n; i++){
        cin >> y >> x1 >> x2;
        plats[i] = Platform{y,x1,x2-1};
    }
    long int sum = 0;
    for(int i = 0; i < n; i++){
        Platform curr = plats[i];
        int mn_l = MAX_V;
        int mn_r = MAX_V;
        for(int j = 0; j < n; j++){
            if(i != j){
                Platform check = plats[j];
                if(curr.y > check.y && curr.x1 >= check.x1 && curr.x1 <= check.x2
                        && curr.y - check.y < mn_l){
                    mn_l = curr.y - check.y;
                }
                if(curr.y > check.y && curr.x2 >= check.x1 && curr.x2 <= check.x2  && curr.y - check.y < mn_r){
                    mn_r = curr.y - check.y;
                }
            }
        }
        if(mn_l == MAX_V) mn_l = curr.y;
        if(mn_r == MAX_V) mn_r = curr.y;
        sum += mn_l + mn_r;
    }
    cout << sum << endl;
}

