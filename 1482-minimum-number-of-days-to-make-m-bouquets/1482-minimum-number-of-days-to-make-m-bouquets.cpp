class Solution {
public:
int solve(int day,vector<int>& bloomDay,int k){
    int cnt=0;
    int boquets=0;
    int n=bloomDay.size();
    for(int i=0;i<n;i++){
        if(day>=bloomDay[i]) cnt++;
        else {
             boquets+=cnt/k;
             cnt=0;
        }
    }
    boquets+=cnt/k;
    return boquets;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n<(long long)m*k) return -1;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(bloomDay[i]>maxi) maxi=bloomDay[i];
        }
        int low=1,high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            int boque=solve(mid,bloomDay,k);
            if(boque<m) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};