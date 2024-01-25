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
    long long count = 0;

    sort(nums.begin(), nums.end()); // Sắp xếp danh sách số nguyên

    for (int i = 0; i < n; i++) {
        int left = 0, right = n - 1;
        while (left < right) {
            if (nums[left] + nums[right] == nums[i] && left != i && right != i) {
                count++;
                left++;
                right--;
            } else if (nums[left] + nums[right] < nums[i] && left != i && right != i) {
                left++;
            } else {
                right--;
            }
        }
    }
    count %= mod;
    cout << count << endl;
    return 0;
}
