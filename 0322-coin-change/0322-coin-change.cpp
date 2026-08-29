class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size(); 
        vector<int> prev(amount+1,0), cur(amount+1,0);
              for(int t=0;t<=amount;t++){
            if(t%coins[0]==0) prev[t]=t/coins[0];
            else prev[t]=1e9;
        }
        for(int index=1;index<n;index++){
            for(int target=0;target<=amount;target++){
                int nottake=prev[target];
                int take=1e9;
                if(coins[index]<=target){
                    take=1+cur[target-coins[index]];
                }
                cur[target]=min(take,nottake);
            }
            prev=cur;
        }
        if(prev[amount]==1e9) return -1;
        else return prev[amount];
    }
};