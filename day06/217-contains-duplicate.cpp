// 题目：217. 存在重复元素
// 思路：哈希集合边遍历边记录，遇到已存在的元素即重复
// 时间复杂度：O(n)，空间复杂度：O(n)

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int x : nums) {
            if (seen.count(x)) return true; // 之前出现过，说明重复
            seen.insert(x);
        }
        return false;
    }
};

// 本地测试用例
int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 1};
    cout << boolalpha << sol.containsDuplicate(nums1) << endl; // 应输出 true
    vector<int> nums2 = {1, 2, 3, 4};
    cout << boolalpha << sol.containsDuplicate(nums2) << endl; // 应输出 false
    return 0;
}
