class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       vector<int> after(4+1,0);
       vector<int> cur(4+1,0);
        for(int index=n-1;index>=0;index--){
            for(int tranNo=3;tranNo>=0;tranNo--){
                int profit=0;
                if(tranNo%2==0){
                    profit=max(-prices[index]+after[tranNo+1],//take
                    after[tranNo]);
                    }//not take
                else{
                    profit=max(prices[index]+after[tranNo+1],//take
                    after[tranNo]);//nottake
                }
                 cur[tranNo]=profit;
            }
            after=cur;
        }
        return after[0];
    }
};