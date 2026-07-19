class Solution {
public:
bool solve(vector<int>& bloomDay, int m, int k,int day){
    long long count=0;
    long long nob=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=day){
            count++;
        }
        else{
            nob+=count/k;
            count=0;
        }
    }
    nob+=count/k;
    return nob>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)m*k) return -1;
        int min=*min_element(bloomDay.begin(),bloomDay.end());
        int max=*max_element(bloomDay.begin(),bloomDay.end());
        int low=min,high=max;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(bloomDay,m,k,mid)==true){
                high=mid-1;
            }
            else{low=mid+1;}
        }
        return low;

    }
};