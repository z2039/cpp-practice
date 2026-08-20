//复习
// 题目：169. 多数元素
// 思路：哈希表计数
// 时间复杂度：O(n)，空间复杂度：O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int n = nums.size();
        for (int num : nums) {
            count[num]++;
            if (count[num] > n / 2) {
                return num;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {3, 2, 3};
    cout << "测试1: " << sol.majorityElement(nums1) << endl;  // 3
    
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "测试2: " << sol.majorityElement(nums2) << endl;  // 2
    
    return 0;
}