class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
       int n=prices.size();
        vector<int> after(2,0);
        vector<int> cur(2,0);
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<2;buy++){
                int profit=0;
                 if(buy==1){
        profit=max(-prices[index]+after[0],//take
        after[1]);//not take
    }
    else{
        profit=max(prices[index]-fee+after[1],//take
        after[0]);//nottake
    }
     cur[buy]=profit;
            }
            after=cur;
        }
        return after[1];
    }
};