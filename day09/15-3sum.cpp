// 题目：15. 三数之和
// 思路：排序后固定一个数 nums[i]，再用左右双指针在 i 之后找两数之和 = -nums[i]；注意去重
// 时间复杂度：O(n^2)，空间复杂度：O(log n)（排序栈空间）

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) break;                 // 最小数都 > 0，不可能凑成 0
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重：固定数相同
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    // 去重：跳过相同的左右指针
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                } else if (sum < 0) {
                    l++; // 和偏小，左指针右移
                } else {
                    r--; // 和偏大，右指针左移
                }
            }
        }
        return res;
    }
};

// 本地测试用例
int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = sol.threeSum(nums);
    cout << "[";
    for (int i = 0; i < (int)res.size(); i++) {
        cout << "[" << res[i][0] << "," << res[i][1] << "," << res[i][2] << "]";
        if (i < (int)res.size() - 1) cout << ",";
    }
    cout << "]" << endl; // 应输出 [[-1,-1,2],[-1,0,1]]
    return 0;
}
