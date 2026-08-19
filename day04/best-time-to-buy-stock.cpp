#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};

int main()
{
    Solution sol;
    // 测试用例 [2,4,1]
    vector<int> prices = {2,4,1};
    int ans = sol.maxProfit(prices);
    cout << "最大利润：" << ans << endl;
    return 0;
}