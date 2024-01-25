#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    const int mod = 100000007;
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] == nums[j] + nums[k] || nums[j] == nums[i] + nums[k] || nums[k] == nums[i] + nums[j]) {
                    count++;
                }
            }
        }
    }

    cout << count % mod << endl;

    return 0;
}