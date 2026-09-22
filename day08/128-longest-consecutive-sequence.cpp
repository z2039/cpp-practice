// 题目：128. 最长连续序列
// 思路：全部数存入哈希集合；只从序列起点（x-1 不在集合中）开始向上数连续长度，保证 O(n)
// 时间复杂度：O(n)，空间复杂度：O(n)

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int best = 0;
        for (int x : s) {
            if (s.count(x - 1)) continue; // x-1 存在，说明 x 不是序列起点，跳过
            int cur = x, len = 0;
            while (s.count(cur)) { // 从起点往后数连续长度
                len++;
                cur++;
            }
            best = max(best, len);
        }
        return best;
    }
};

// 本地测试用例
int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutive(nums) << endl; // 应输出 4（1,2,3,4）
    return 0;
}
