// 题目：242.有效的字母异位词
// 思路：字母计数数组，s字符计数+1，t字符计数-1，全部为0则是异位词
// 时间复杂度：O(n)，空间复杂度：O(1)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false; // 长度不同一定不是异位词
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++; // 统计 s 中每个字母出现次数
        for (char c : t) cnt[c - 'a']--; // 用 t 抵消
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) return false; // 有字母数量对不上
        }
        return true;
    }
};

// 本地测试用例
int main() {
    Solution sol;
    cout << boolalpha << sol.isAnagram("anagram", "nagaram") << endl; // 应输出 true
    cout << boolalpha << sol.isAnagram("rat", "car") << endl;         // 应输出 false
    return 0;
}
