#include <iostream>
#include <vector>

using namespace std;

/*
 * 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
 * 思路：将其转换为最大子数组，用 动态规划或分治法
 */




int maxProfit(vector<int>& prices) {
    if(prices.size()==1){
        return 0;
    }

    //转换为最大子数组问题
    vector<int> arr(prices.size()-1);
    for(int i=0;i<prices.size()-1;++i){
        arr[i] = prices[i+1] - prices[i];
    }

    //使用动态规划求解
    vector<int> v(prices.size()-1);
    v[0] = arr[0];
    int output=v[0];
    for(int i=1;i<prices.size()-1;++i){
        v[i] = std::max(v[i-1]+arr[i],arr[i]);
        if(v[i]>output){
            output = v[i];
        }
    }

    return output>=0?output:0;
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int> price={7,6,4,3,1};

    cout<<maxProfit(price)<<endl;


    return 0;
}
