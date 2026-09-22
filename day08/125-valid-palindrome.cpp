// 题目：125. 验证回文串
// 思路：左右双指针，跳过非字母数字并统一转小写，相向比较
// 时间复杂度：O(n)，空间复杂度：O(1)

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = (int)s.size() - 1;
        while (l < r) {
            while (l < r && !isalnum((unsigned char)s[l])) l++; // 跳过非字母数字
            while (l < r && !isalnum((unsigned char)s[r])) r--;
            if (tolower((unsigned char)s[l]) != tolower((unsigned char)s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};

// 本地测试用例
int main() {
    Solution sol;
    cout << boolalpha << sol.isPalindrome("A man, a plan, a canal: Panama") << endl; // true
    cout << boolalpha << sol.isPalindrome("race a car") << endl;                     // false
    return 0;
}
