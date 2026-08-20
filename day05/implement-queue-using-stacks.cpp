// 题目：232. 用栈实现队列
// 思路：两个栈。inStack 负责入队，outStack 负责出队。
//       outStack 空时，把 inStack 全部倒过去
// 时间复杂度：均摊 O(1)

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> inStack;
    stack<int> outStack;
    
    MyQueue() {}
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        peek();           // 确保 outStack 有元素
        int val = outStack.top();
        outStack.pop();
        return val;
    }
    
    int peek() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << "peek: " << q.peek() << endl;   // 1
    cout << "pop: " << q.pop() << endl;     // 1
    cout << "empty: " << q.empty() << endl; // false
    cout << "pop: " << q.pop() << endl;     // 2
    cout << "empty: " << q.empty() << endl; // true
    
    return 0;
}