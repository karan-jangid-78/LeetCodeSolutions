class Solution {
public:
int solve(int capacity,vector<int>& weights){
    int cnt=1;
    int n=weights.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=weights[i];
        if(sum>capacity){ cnt++; sum=weights[i];} 
    }
    return cnt;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=weights[i];
            if(weights[i]>maxi) maxi=weights[i];
        }
        int low=maxi,high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            int no_of_days=solve(mid,weights);
            if(no_of_days>days) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};