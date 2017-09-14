#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Clause {
public:
    Clause() = default;

    Clause(int size) {
        exists = vector<bool>(size, false);
        inverted = vector<bool>(size, false);
        sat = false;
        unset = 0;
    }

    bool sat;
    int unset;

    vector<bool> exists;
    vector<bool> inverted;
private:
};


bool can_set(vector<Clause> &clauses, int i, bool val, vector<vector<int>> &in) {
    for (int j = 0; j < in[i].size(); j++) {
        Clause curr = clauses[in[i][j]];
        if (!curr.sat && curr.unset < 2 && curr.inverted[i] == val) {
            return false;
        }

    }
    return true;
}

void set_c(vector<Clause> &clauses, int i, bool val, vector<vector<int>> &in) {
    for (int j = 0; j < in[i].size(); j++) {
        Clause *curr = &clauses[in[i][j]];
        curr->unset--;
        if (curr->inverted[i] != val) {
            curr->sat = true;
        }
    }
}

bool rec(vector<Clause> clauses, int i, bool val, vector<vector<int>> &in, int size) {
    if (i == size) {
        return true;
    }
    set_c(clauses, i, val, in);
    if (can_set(clauses, i + 1, false, in)) {
        if (can_set(clauses, i + 1, true, in)) {
            return rec(clauses, i + 1, true, in, size) || rec(clauses, i + 1, false, in, size);
        } else {
            return rec(clauses, i + 1, false, in, size);
        }
    } else if (can_set(clauses, i + 1, true, in)) {
        return rec(clauses, i + 1, true, in, size);
    } else {
        return false;
    }

}

void create_class(Clause & n_clas, int name, bool val, vector<vector<int>> & var_in, int i) {
    if(n_clas.exists[name] && n_clas.inverted[name] != val){
        n_clas.sat = true;
    }
    n_clas.exists[name] = true;
    n_clas.inverted[name] = val;
    auto f = find(var_in[name].begin(), var_in[name].end(), i);
    if (f == var_in[name].end()) var_in[name].push_back(i);
}

int main() {
    int tc = 0;
    string tc_s;
    getline(cin, tc_s);
    tc = stoi(tc_s);
    while (tc--) {

        int n = 0, m = 0;
        string nm;
        getline(cin, nm);
        string tp = "";
        for (char c: nm) {
            if (c == ' ') {
                n = stoi(tp);
                tp = "";
            } else {
                tp += c;
            }
        }
        m = stoi(tp);
        vector<Clause> clauses(m);
        vector<vector<int>> var_in(n + 1);

        for (int i = 0; i < m; i++) {
            string clas;
            getline(cin, clas);
            string tmp = "";
            Clause n_clas(n + 1);
            for (int c : clas) {
                if (c == ' ') {
                    if (tmp != "v" && tmp.size()) {
                        if (tmp[0] == '~') {
                            create_class(n_clas, stoi(tmp.substr(2)), true, var_in,i);
                        } else {
                            create_class(n_clas, stoi(tmp.substr(1)), false, var_in,i);
                        }
                    }
                    tmp = "";
                } else {
                    tmp += c;
                }
            }
            if (tmp.size()) {
                if (tmp[0] == '~') {
                    create_class(n_clas, stoi(tmp.substr(2)), true, var_in,i);
                } else {
                    create_class(n_clas, stoi(tmp.substr(1)), false, var_in,i);
                }
            }
            for (bool b: n_clas.exists) {
                if (b) n_clas.unset++;
            }
            clauses[i] = n_clas;


        }
        bool sat = false;
        if (can_set(clauses, 1, true, var_in)) {
            if (can_set(clauses, 1, false, var_in)) {
                sat = rec(clauses, 1, false, var_in, n) || rec(clauses, 1, true, var_in, n);
            } else {
                sat = rec(clauses, 1, true, var_in, n);
            }
        } else if (can_set(clauses, 1, false, var_in)) {
            sat = rec(clauses, 1, false, var_in, n);
        }
        if (sat) cout << "satisfiable" << endl;
        else cout << "unsatisfiable" << endl;

    }

    return 0;
}