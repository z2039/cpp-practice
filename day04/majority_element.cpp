#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 解法一：哈希表计数
int majorityElement_hash(vector<int>& nums) {
    unordered_map<int, int> count;
    int n = nums.size();
    for (int num : nums) {
        count[num]++;
        if (count[num] > n / 2) return num;
    }
    return -1;
}

// 解法二：摩尔投票法（空间更优）
int majorityElement_vote(vector<int>& nums) {
    int candidate = 0, votes = 0;
    for (int num : nums) {
        if (votes == 0) candidate = num;
        votes += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

int main() {
    // 测试用例
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << "数组：";
    for (int num : nums) cout << num << " ";
    cout << endl;

    cout << "哈希表解法结果：" << majorityElement_hash(nums) << endl;
    cout << "摩尔投票法结果：" << majorityElement_vote(nums) << endl;

    return 0;
}