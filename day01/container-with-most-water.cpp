// 题目：11. 盛最多水的容器
// 思路：左右双指针，移动短板
// 时间复杂度：O(n)，空间复杂度：O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        
        while (left < right) {
            int h = min(height[left], height[right]);
            int area = h * (right - left);
            maxArea = max(maxArea, area);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxArea;
    }
};

int main() {
    Solution sol;
    
    // 测试用例1：题目示例
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "测试1: " << sol.maxArea(height1) << endl;  // 预期: 49
    
    // 测试用例2：只有两个元素
    vector<int> height2 = {1, 1};
    cout << "测试2: " << sol.maxArea(height2) << endl;  // 预期: 1
    
    // 测试用例3：递增序列
    vector<int> height3 = {1, 2, 3, 4, 5};
    cout << "测试3: " << sol.maxArea(height3) << endl;  // 预期: 6 (1和5: min(1,5)*4=4? 不对，应该是2和5: min(2,5)*3=6)
    
    // 测试用例4：递减序列
    vector<int> height4 = {5, 4, 3, 2, 1};
    cout << "测试4: " << sol.maxArea(height4) << endl;  // 预期: 6
    
    return 0;
}