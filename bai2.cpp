#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Treasure {
    int x, y, gold;
};

bool compare(const Treasure& t1, const Treasure& t2) {
    if (t1.x == t2.x) {
        return t1.y < t2.y;
    }
    return t1.x < t2.x;
}

int main() {
    int n;
    cin >> n;
    vector<Treasure> treasures(n);
    for (int i = 0; i < n; i++) {
        cin >> treasures[i].x >> treasures[i].y >> treasures[i].gold;
    }

    sort(treasures.begin(), treasures.end(), compare);

    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = treasures[i].gold;
        for (int j = 0; j < i; j++) {
            if (treasures[i].x >= treasures[j].x && treasures[i].y >= treasures[j].y) {
                dp[i] = max(dp[i], dp[j] + treasures[i].gold);
            }
        }
    }

    int maxGold = 0;
    for (int i = 0; i < n; i++) {
        maxGold = max(maxGold, dp[i]);
    }

    cout << maxGold << endl;

    return 0;
}