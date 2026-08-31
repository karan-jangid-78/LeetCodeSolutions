class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> prev(2,0), cur(2,0);
        prev[0]=prev[1]=0;
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<2;buy++){
                int profit=0;
                 if(buy==1){
        profit=max(-prices[index]+prev[0],//take
        prev[1]);//not take
    }
    else{
        profit=max(prices[index]+prev[1],//take
        prev[0]);//nottake
    }
     cur[buy]=profit;
            }
            prev=cur;
        }
        return prev[1];
    }
};