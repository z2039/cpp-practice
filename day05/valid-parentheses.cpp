// 题目：20. 有效的括号
// 思路：栈。左括号入栈，右括号看栈顶是否匹配
// 时间复杂度：O(n)，空间复杂度：O(n)

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> match = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty() || st.top() != match[c]) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    
    cout << boolalpha;  // 让 true/false 直接输出文字
    cout << "\"()\": " << sol.isValid("()") << endl;           // true
    cout << "\"()[]{}\": " << sol.isValid("()[]{}") << endl;   // true
    cout << "\"(]\": " << sol.isValid("(]") << endl;           // false
    cout << "\"([)]\": " << sol.isValid("([)]") << endl;       // false
    cout << "\"{[]}\": " << sol.isValid("{[]}") << endl;       // true
    
    return 0;
}