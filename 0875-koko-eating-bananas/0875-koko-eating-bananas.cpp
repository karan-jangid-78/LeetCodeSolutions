class Solution {
public:
long long solve(vector<int>& piles,int k){
    long long  hr=0;
    for(int i=0;i<piles.size();i++){
        hr+=ceil((double)piles[i]/(double)k);
    }
    return hr;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxx=*max_element(piles.begin(),piles.end());
        int low=1,high=maxx;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long hrr=solve(piles,mid);
            if(hrr<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};