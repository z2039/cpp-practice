#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        int slow = 2;
        for (int fast = 2; fast < nums.size(); ++fast) {
            if (nums[fast] != nums[slow - 2]) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

void printVector(const vector<int>& nums, int len) {
    cout << "[";
    for (int i = 0; i < len; i++) {
        if (i > 0) cout << ",";
        cout << nums[i];
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    // 测试用例1
    vector<int> nums1 = {1,1,1,2,2,3};
    int len1 = sol.removeDuplicates(nums1);
    cout << "测试1 长度=" << len1 << endl;
    printVector(nums1, len1);

    // 测试用例2
    vector<int> nums2 = {0,0,1,1,1,1,2,3,3};
    int len2 = sol.removeDuplicates(nums2);
    cout << "测试2 长度=" << len2 << endl;
    printVector(nums2, len2);

    return 0;
}