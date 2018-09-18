class Solution {
public:
	// Method 1
    int maxProfit(vector<int>& prices) {
        int size = static_cast<int>(prices.size());
        if(size <= 1) return 0;
        int maxProfit = 0;
        int vally, peak;
        int i = 0;
        while(i < size)
        {
            while(i+1 < size && prices[i] >= prices[i+1])
                ++i;
            vally = prices[i];
            while(i+1 < size && prices[i] <= prices[i+1])
                ++i;
            peak = prices[i];
            maxProfit += peak - vally;
            ++i;
        }
        return maxProfit;
    }
    
	// Method 2
    int maxProfit(vector<int>& prices)
    {
        int size = static_cast<int>(prices.size());
        if(size <= 1) return 0;
        int maxProfit = 0;
        int i = 0;
        while(i < size)
        {
            while(i+1 < size && prices[i] <= prices[i+1])
            {
                maxProfit += prices[i+1] - prices[i];
                ++i;
            }          
            ++i;
        }
        return maxProfit;
    }
};