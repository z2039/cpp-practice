// 题目：26. 删除有序数组中的重复项
// 思路：快慢指针，数组有序则重复元素相邻
// 时间复杂度：O(n)，空间复杂度：O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;  // 空数组边界
        
        int slow = 1;  // 从1开始，第一个元素必定保留
        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[fast - 1]) {  // 发现新元素
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;  // slow就是新数组长度
    }
};

int main() {
    Solution sol;
    
    // 测试用例1：正常情况
    vector<int> nums1 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int len1 = sol.removeDuplicates(nums1);
    cout << "长度: " << len1 << ", 数组: [";
    for (int i = 0; i < len1; i++) {
        cout << nums1[i];
        if (i < len1 - 1) cout << ",";
    }
    cout << "]" << endl;
    // 预期输出：长度: 5, 数组: [0,1,2,3,4]
    
    // 测试用例2：空数组
    vector<int> nums2;
    cout << "空数组长度: " << sol.removeDuplicates(nums2) << endl;
    // 预期输出：0
    
    // 测试用例3：全部相同
    vector<int> nums3 = {1, 1, 1};
    int len3 = sol.removeDuplicates(nums3);
    cout << "全相同长度: " << len3 << endl;
    // 预期输出：1
    
    return 0;
}