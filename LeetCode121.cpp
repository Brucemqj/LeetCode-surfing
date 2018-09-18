class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = static_cast<int>(prices.size());
        if(len <= 1) return 0;
        int maxProfit = 0, curMin = prices[0];
        for(int i=1; i<len; ++i)
        {
            if(prices[i] > curMin)
            {
                int curProfit = prices[i] - curMin;
                maxProfit = (curProfit > maxProfit) ? curProfit : maxProfit;
            }
            if(prices[i] < curMin)
                curMin = prices[i];
        }
        return maxProfit;
    }
};