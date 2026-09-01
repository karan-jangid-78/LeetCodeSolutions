class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> after(2,vector<int>(3,0));
        vector<vector<int>> cur(2,vector<int>(3,0));
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<2;buy++){
                for(int no_of_transactions=1;no_of_transactions<=2;no_of_transactions++){
                    int profit=0;
                    if(buy==1){
                        profit=max(-prices[index]+after[0][no_of_transactions],//take
                        after[1][no_of_transactions]);//not take
                    }
                    else{
                        profit=max(prices[index]+after[1][no_of_transactions-1],//take
                        after[0][no_of_transactions]);//nottake
                    }
                     cur[buy][no_of_transactions]=profit;
                }
            }
            after=cur;
        }
        return after[1][2];
    }
};