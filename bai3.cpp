#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int total = 0;
    for (int value : values) {
        total += value;
    }

    int target = total / 2;

    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int value : values) {
        for (int j = target; j >= value; j--) {
            dp[j] = dp[j] || dp[j - value];
        }
    }

    int minDiff = INT_MAX;
    for (int j = target; j >= 0; j--) {
        if (dp[j]) {
            minDiff = total - 2 * j;
            break;
        }
    }

    cout << minDiff << endl;

    return 0;
}