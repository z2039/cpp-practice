// 题目：283. 移动零
// 思路：快慢指针。fast找非零元素，slow指向下一个该放的位置
// 时间复杂度：O(n)，空间复杂度：O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        // 第一遍：把非零元素按顺序搬到前面
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        // 第二遍：slow到末尾全部填0
        for (int i = slow; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

// 打印数组的辅助函数
void printVector(const vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    // 测试用例1：正常情况
    vector<int> nums1 = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums1);
    cout << "测试1: ";
    printVector(nums1);
    // 预期: [1,3,12,0,0]
    
    // 测试用例2：全零
    vector<int> nums2 = {0, 0, 0};
    sol.moveZeroes(nums2);
    cout << "测试2: ";
    printVector(nums2);
    // 预期: [0,0,0]
    
    // 测试用例3：没有零
    vector<int> nums3 = {1, 2, 3};
    sol.moveZeroes(nums3);
    cout << "测试3: ";
    printVector(nums3);
    // 预期: [1,2,3]
    
    // 测试用例4：只有一个元素
    vector<int> nums4 = {0};
    sol.moveZeroes(nums4);
    cout << "测试4: ";
    printVector(nums4);
    // 预期: [0]
    
    return 0;
}