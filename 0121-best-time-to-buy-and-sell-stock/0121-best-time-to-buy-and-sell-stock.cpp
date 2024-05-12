class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size())
            return 0;
        if(prices.size()==1)
            return 0;
        int firstIdx=0;
        int secIdx=1;
        int maxres=0;
        while((secIdx<prices.size()))
        {
            //comparisons
            maxres=max(maxres,(prices[secIdx]-prices[firstIdx]));
            //movement
            if(prices[firstIdx]>prices[secIdx])
            {
                ++firstIdx;
                if(secIdx==firstIdx)
                    ++secIdx;
            }
            else
                ++secIdx;
        
        }
        return maxres;
    }
};