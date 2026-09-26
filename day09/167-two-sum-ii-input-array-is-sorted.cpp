// 题目：167. 两数之和 II - 输入有序数组
// 思路：数组已排序，左右双指针：和小了左指针右移，和大了右指针左移
// 时间复杂度：O(n)，空间复杂度：O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = (int)numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) return {l + 1, r + 1}; // 题目要求 1 起始下标
            if (sum < target) l++; // 和偏小，需要更大的数
            else r--;              // 和偏大，需要更小的数
        }
        return {};
    }
};

// 本地测试用例
int main() {
    Solution sol;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = sol.twoSum(numbers, target);
    cout << "[" << res[0] << "," << res[1] << "]" << endl; // 应输出 [1,2]
    return 0;
}
