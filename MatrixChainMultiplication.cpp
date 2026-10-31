#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    if (n < 1) {
        cout << "Number of matrices must be positive.\n";
        return 0;
    }

    vector<int> p(n + 1);

    cout << "Enter " << n + 1 << " dimensions: ";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];

        if (p[i] <= 0) {
            cout << "Dimensions must be positive.\n";
            return 0;
        }
    }

    vector<vector<long long>> dp(n + 1,
                                vector<long long>(n + 1, 0));

    for (int length = 2; length <= n; length++) {
        for (int i = 1; i <= n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++) {
                long long cost =
                    dp[i][k] +
                    dp[k + 1][j] +
                    1LL * p[i - 1] * p[k] * p[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << "Minimum scalar multiplications: " << dp[1][n] << '\n';

    return 0;
}