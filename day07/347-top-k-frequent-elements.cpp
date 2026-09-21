// 题目：347. 前 K 个高频元素
// 思路：哈希表统计频次，再按频次分桶（桶排序），从高频到低频取 k 个
// 时间复杂度：O(n)，空间复杂度：O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        // 桶的下标即频次，桶里放具有该频次的元素
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto& p : freq) {
            bucket[p.second].push_back(p.first);
        }

        vector<int> res;
        // 从最高频次往下取，凑够 k 个
        for (int i = (int)bucket.size() - 1; i >= 0 && (int)res.size() < k; i--) {
            for (int x : bucket[i]) {
                res.push_back(x);
                if ((int)res.size() == k) break;
            }
        }
        return res;
    }
};

// 本地测试用例
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> res = sol.topKFrequent(nums, k);
    cout << "[";
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        if (i < (int)res.size() - 1) cout << ",";
    }
    cout << "]" << endl; // 应输出 [1,2]
    return 0;
}
