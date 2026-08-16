// 题目：88. 合并两个有序数组
// 思路：从后往前双指针，避免覆盖 nums1 未处理元素
// 时间复杂度：O(m+n)，空间复杂度：O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = m - 1;        // nums1 有效元素末尾
        int k = n - 1;        // nums2 末尾
        int p = m + n - 1;    // 填充位置
        
        while (k >= 0) {      // nums2 还有元素要放
            if (j >= 0 && nums1[j] > nums2[k]) {
                nums1[p] = nums1[j];
                j--;
            } else {
                nums1[p] = nums2[k];
                k--;
            }
            p--;
        }
    }
};

// 打印数组
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
    
    // 测试用例1：题目示例
    vector<int> nums1_1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2_1 = {2, 5, 6};
    sol.merge(nums1_1, 3, nums2_1, 3);
    cout << "测试1: ";
    printVector(nums1_1);
    // 预期: [1,2,2,3,5,6]
    
    // 测试用例2：nums2 为空
    vector<int> nums1_2 = {1};
    vector<int> nums2_2;
    sol.merge(nums1_2, 1, nums2_2, 0);
    cout << "测试2: ";
    printVector(nums1_2);
    // 预期: [1]
    
    // 测试用例3：nums1 为空
    vector<int> nums1_3 = {0};
    vector<int> nums2_3 = {1};
    sol.merge(nums1_3, 0, nums2_3, 1);
    cout << "测试3: ";
    printVector(nums1_3);
    // 预期: [1]
    
    return 0;
}