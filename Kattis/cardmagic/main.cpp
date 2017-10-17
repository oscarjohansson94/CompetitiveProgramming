#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K, T;
    cin >> N >> K >> T;
    vector<vector<int>> dp(T + 1, vector<int>(N + 1));
    for (int k = 1; k <= K  && k <= T; k++) {
        dp[k][0] = 1;
    }
    for (int j = 1; j < N; j++) {
        for (int i = j; i <= T; i++) {
            for (int k = 1; k <= K; k++) {
                if (i - k >= 0) {
                    dp[i][j] += dp[i-k][j - 1];
                    dp[i][j] %= 1000000009;
                }
            }
        }
    }
    cout << dp[T][N-1] << endl;
    return 0;
}
