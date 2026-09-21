// 题目：238. 除自身以外数组的乘积
// 思路：前缀积 × 后缀积。先把前缀积存入结果数组，再从右往左乘上后缀积
// 时间复杂度：O(n)，空间复杂度：O(1)（输出数组不计入）

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        // 第一遍：res[i] = nums[0..i-1] 的乘积（前缀）
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            res[i] = prefix;
            prefix *= nums[i];
        }

        // 第二遍：从右往左乘上后缀 nums[i+1..n-1] 的乘积
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= suffix;
            suffix *= nums[i];
        }
        return res;
    }
};

// 本地测试用例
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = sol.productExceptSelf(nums);
    cout << "[";
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        if (i < (int)res.size() - 1) cout << ",";
    }
    cout << "]" << endl; // 应输出 [24,12,8,6]
    return 0;
}
