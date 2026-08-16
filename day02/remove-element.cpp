// 题目：27. 移除元素
// 思路：快慢指针，fast 遍历数组，slow 指向不等于 val 的元素该放的位置
// 时间复杂度：O(n)，空间复杂度：O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

// 打印数组前 n 个元素的辅助函数
void printVector(const vector<int>& nums, int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << nums[i];
        if (i < n - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    // 测试用例1：题目示例
    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    int len1 = sol.removeElement(nums1, val1);
    cout << "测试1 长度: " << len1 << ", 数组: ";
    printVector(nums1, len1);
    // 预期: 长度: 2, 数组: [2,2]
    
    // 测试用例2：没有要移除的元素
    vector<int> nums2 = {1, 2, 3, 4};
    int val2 = 5;
    int len2 = sol.removeElement(nums2, val2);
    cout << "测试2 长度: " << len2 << ", 数组: ";
    printVector(nums2, len2);
    // 预期: 长度: 4, 数组: [1,2,3,4]
    
    // 测试用例3：全部都要移除
    vector<int> nums3 = {2, 2, 2};
    int val3 = 2;
    int len3 = sol.removeElement(nums3, val3);
    cout << "测试3 长度: " << len3 << endl;
    // 预期: 0
    
    return 0;
}