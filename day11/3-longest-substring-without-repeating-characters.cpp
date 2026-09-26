// 题目：3. 无重复字符的最长子串
// 思路：滑动窗口 + 数组记录字符最后出现位置；右指针扩张，遇重复左边界跳到重复位置+1
// 时间复杂度：O(n)，空间复杂度：O(Σ)（固定 128，视为 O(1)）

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(128, -1); // 记录每个字符最近一次出现的下标
        int left = 0, best = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];
            if (last[c] >= left) {      // 该字符在当前窗口内已出现过
                left = last[c] + 1;     // 窗口左边界跳到上次出现位置的下一位
            }
            last[c] = right;
            best = max(best, right - left + 1); // 更新窗口最大长度
        }
        return best;
    }
};

// 本地测试用例
int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl; // 应输出 3（"abc"）
    cout << sol.lengthOfLongestSubstring("bbbbb") << endl;    // 应输出 1
    cout << sol.lengthOfLongestSubstring("pwwkew") << endl;   // 应输出 3（"wke"）
    return 0;
}
