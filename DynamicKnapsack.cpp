#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    if (n < 0 || capacity < 0) {
        cout << "Invalid input.\n";
        return 0;
    }

    vector<int> weight(n), profit(n);

    cout << "Enter weight and profit of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> profit[i];

        if (weight[i] <= 0 || profit[i] < 0) {
            cout << "Weight must be positive and profit nonnegative.\n";
            return 0;
        }
    }

    vector<vector<int> > dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {

            if (weight[i - 1] <= w) {
                int include = profit[i - 1]
                            + dp[i - 1][w - weight[i - 1]];

                int exclude = dp[i - 1][w];

                dp[i][w] = max(include, exclude);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "\nMaximum profit: " << dp[n][capacity] << "\n";

    vector<int> selected;
    int remaining = capacity;

    for (int i = n; i > 0; i--) {
        if (dp[i][remaining] != dp[i - 1][remaining]) {
            selected.push_back(i);
            remaining -= weight[i - 1];
        }
    }

    reverse(selected.begin(), selected.end());

    cout << "Selected items: ";
    if (selected.empty()) {
        cout << "None";
    } else {
        for (int i = 0; i < static_cast<int>(selected.size()); i++) {
            cout << selected[i] << " ";
        }
    }

    cout << "\nTotal weight: " << capacity - remaining << "\n";

    return 0;
}