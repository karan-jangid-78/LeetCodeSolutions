class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
         vector<int> prev(amount+1,0), cur(amount+1,0);
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0) prev[target]=1;
        }
        for(int index=1;index<n;index++){
            for(int target=0;target<=amount;target++){
        unsigned long long nottake=prev[target];
        unsigned long long take=0;
        if(coins[index]<=target){
            take=cur[target-coins[index]];
        }
        cur[target]= take+nottake;
            }
            prev=cur;
        }
        return (int)prev[amount];
    }
};