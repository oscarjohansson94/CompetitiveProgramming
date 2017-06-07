/*
 * Oscar Johansson
 * oscjo411
 */

#include <iostream>
#include <vector>

using namespace std;

int inf = 1000000;

// Find all path between nodes. Will detect negative cycles and set the value to -inf
vector<vector<int>> Floyd_Warshall(vector<vector<int>> values, int n) {
    // Find value
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (values[i][j] > values[i][k] + values[k][j]
                    && values[i][k] < inf
                    && values[k][j] < inf) {
                    values[i][j] = values[i][k] + values[k][j];
                }
            }
        }
    }
    // Detect negative cycle and set value to "-inf"
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (values[k][k] < 0 && values[i][k] < inf && values[k][j] < inf) {
                    values[i][j] = -inf;
                }
            }
        }
    }
    return values;
}

int main() {
    int n = 0, m = 0, q = 0;
    while (cin >> n >> m >> q) {
        // Exit condition
        if (!n && !m && !q) {
            break;
        }

        // Init table with high default value
        vector<vector<int>> values(n, vector<int>(n, inf));

        // All nodes have cost 0 to themself
        for (int i = 0; i < n; i++) {
            values[i][i] = 0;
        }
        int u = 0, v = 0, w = 0;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            // This makes it possible that a node  can have negative value to itself, creating a negative cycle
            values[u][v] = min(values[u][v], w);
        }
        // Calculate cost for all path
        values = Floyd_Warshall( values, n);

        // Manage the queries and output result
        for (int i = 0; i < q; i++) {
            cin >> u >> v;
            int result = values[u][v];
            if (result >= inf) {
                cout << "Impossible" << endl;
            } else if (result <= -inf) {
                cout << "-Infinity" << endl;
            } else {
                cout << result << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
