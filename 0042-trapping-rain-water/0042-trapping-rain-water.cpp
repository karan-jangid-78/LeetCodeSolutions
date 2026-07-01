class Solution {
public://not an optmizeed sol 
    int trap(vector<int>& height) {
        int n=height.size();
vector<int> prefixmax(n);
prefixmax[0]=height[0];
for(int i=1;i<n;i++){
    prefixmax[i]=max(prefixmax[i-1],height[i]);
}
vector<int> suffixmax(n);
suffixmax[n-1]=height[n-1];
for(int i=n-2;i>=0;i--){
    suffixmax[i]=max(suffixmax[i+1],height[i]);
}
        int total=0;
        for(int i=0;i<n;i++){
            int lmax=prefixmax[i];
           int rmax=suffixmax[i];
            if(lmax>height[i]&&rmax>height[i]){
            total+=min(lmax,rmax)-height[i];
            }
        }
        return total;
    }
};