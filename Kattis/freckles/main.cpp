//
//Oscar Johansson
//oscjo411
//
//Comment:
//I will use Prim since it is faster than Kruskal, and have the recommended
//time complexity for the lab.
//
//To get the required time complexity I need to respresent the graph as a adjecent list solve using a
//binary heap. Since this is C++ I will used a priority queue. I will modify my djikstra implementation.
//

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <iomanip>

using namespace std;

struct Edge {
    int s, e;
    double w = 0.0;
};

struct Coord {
    double x = 0.0;
    double y = 0.0;
};

struct Tree {
    vector<Edge> path;
    double cost = 0.0;
};

/* Used to sort in lexicographic order */
bool comp(const Edge &l, const Edge &r) {
    if (l.s == r.s) {
        return l.e < r.e;
    } else {
        return l.s < r.s;
    }
}

bool operator<(const Edge &l, const Edge &r) {
    return l.w < r.w;
}

bool operator>(const Edge &l, const Edge &r) {
    return l.w > r.w;
}

using namespace std;
int inf = 10000000;

Tree prim(int number_of_nodes, vector<vector<Edge>> graph) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    Tree t;
    t.path = vector<Edge>();
    t.cost = 0.0;
    vector<bool> in_tree(number_of_nodes, false);
    /* Insert start node */
    for(int i = 0; i < graph[0].size(); i++){
        pq.push(graph[0][i]);
    }
    in_tree[0] = true;

    /* Iterate until every edge has been handled */
    while (!pq.empty()) {
        Edge c = pq.top();
        pq.pop();
        if(in_tree[c.s] && in_tree[c.e]){
            continue;
        }
        if(in_tree[c.e]){
            for(int i = 0; i < graph[c.s].size(); i++){
                pq.push(graph[c.s][i]);
            }
        }
        if(in_tree[c.s]){
            for(int i = 0; i < graph[c.e].size(); i++){
                pq.push(graph[c.e][i]);
            }
        }
        /* So they will be printed in correct order */
        Edge r;
        r.w = c.w;
        r.s = min(c.e,c.s);
        r.e = max(c.e,c.s);
        t.path.push_back(r);

        /* Mark both nodes as used */
        in_tree[c.s] = true;
        in_tree[c.e] = true;

        /* Update the cost */
        t.cost += 1.0*c.w;

    }



    return t;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::ios::sync_with_stdio(false);
    int TC = 0;
    cin >> TC;
    for(int q = 0; q < TC; q++){
        int m = 0;
        cin >> m;
        vector<Coord> coords(m);
        for(int i = 0; i < m; i++){
            Coord n;
            double x, y;
            cin >> y >> x;
            n.y = y;
            n.x = x;
            coords[i] = n;
        }
        vector<vector<Edge>> graph(m);
        for(int i = 0; i < coords.size(); i++){
            for(int j = 0; j < coords.size();j++){
                if(i != j){
                    Edge n;
                    n.s = i;
                    n.e = j;
                    n.w = hypot(abs(coords[i].x-coords[j].x), abs(coords[i].y-coords[j].y));
                    graph[i].push_back(n);
                }
            }
        }

        /* Represent graph as adjecent list of edges
         * Edges are undirectional */

        /* Get MST */
        Tree t = prim(m, graph);
        /* Sort them */
        sort(t.path.begin(), t.path.end(), comp);

        int tst = t.path.size();
        cout << fixed << setprecision(2);
        if(tst == m-1){
            cout << t.cost << endl;

        } else {
            cout << "Impossible" << endl;
        }


    }
    return 0;
}