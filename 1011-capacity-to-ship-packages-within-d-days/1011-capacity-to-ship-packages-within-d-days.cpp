class Solution {
public:
bool solve(vector<int>& weights, int days,int capacity){
    int count=0;
    int nod=0;
    for(int i=0;i<weights.size();i++){
        count+=weights[i];
        if(count>capacity){
            nod++;
            count=weights[i];
        }
        else if(count==capacity){
            count=0;
            nod++;
        }
        else{continue;}
    }
    if(count>0){
        nod++;
    }
    return nod<=days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=accumulate(weights.begin(),weights.end(),0);
        int max=*max_element(weights.begin(),weights.end());
        int low=max,high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(weights,days,mid)==true){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};