#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <set>

using namespace std;

/*
 * Oscar Johansson
 * oscjo411
 */


/*
 * Struct used to store the intervals
 */
struct Interval {
    double s;
    double e;
    int pos;
};

/*
 * Used to sort the vector of Intervals
 */
bool compare_struct(const Interval &lhs, const Interval &rhs) {

    return lhs.s < rhs.s;

}

/*
 * To handle float comparison
 */
bool are_same(double a, double b) {
    return fabs(a - b) < numeric_limits<double>::epsilon();
}

/*
 * Solver
 */
vector<int> cover(Interval wanted, vector<Interval> intervals) {

    bool fail = false;
    int result = 0;
    vector<int> results;
    sort(intervals.begin(), intervals.end(), compare_struct);
    set<int> used_i;
    for (double i = wanted.s; i < wanted.e;){ //|| are_same(i, wanted.e);) {
        Interval best;
        double dist = -1;
        for (int j = 0; j < intervals.size(); j++) {
            if ((intervals.at(j).s < i || are_same(intervals.at(j).s, i)) &&
                    (intervals.at(j).e > i || are_same(intervals.at(j).e, i))) {
                if (are_same(dist, -1)) {
                    best = intervals.at(j);
                    dist = fabs(i - intervals.at(j).e);
                } else if (fabs(i - intervals.at(j).e) > dist) {
                    best = intervals.at(j);
                    dist = fabs(i - intervals.at(j).e);

                }
            }
        }

        /* Break if no interval is covering the current position */
        if (are_same(dist, -1)) {
            fail = true;
            break;
        }
        /* If the only possible interval already is chosen */
        if (used_i.count(best.pos)) {
            break;
        }
        result++;
        results.push_back(best.pos);
        used_i.insert(best.pos);

        i = best.e + numeric_limits<double>::epsilon();
    }
    if(fail){
        /* Return empty vector if no interval is possible */
        return vector<int>();
    } else {
        return results;
    }

    }

    int main() {
        int tc = 0;
        cin >> tc;
        while(tc--){
            vector<Interval> intervals;
            double   we = 0;
            cin >> we;
            Interval wanted{0, we};
            double t1 = 0, t2 = 0;
            int i = 0;
            while(cin >> t1 >> t2 && !(!t1 && !t2)){
                intervals.push_back(Interval{t1, t2, i});
                i++;
            }
            vector<int> result = cover(wanted, intervals);
            if(!result.size() || (result.size() && intervals[result[result.size()-1]].e < wanted.e)){
                cout << 0 << endl;
            } else {
                cout << result.size() << endl;
                bool first = true;
                for(int i = 0; i < result.size(); i++){
                    cout << intervals[result[i]].s
                        << " " << intervals[result[i]].e
                        << endl;
                }
            }
            if(tc) cout << endl;
        }
        return 0;
    }
