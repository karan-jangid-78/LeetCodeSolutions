class Solution {
public://an optmized sol..it uses two pointer approach and the thought process comes by that we neend only min from lmax,rmax so we need only one either lmax or rmax 
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int lmax=0,rmax=0,total=0;
        while(l<r){
            if(height[l]<height[r]){// it means there is larger building in right and then we only look for lmax
                if(lmax>height[l]){//it means water can be trapped 
                    total+=lmax-height[l];
                }
                else{//it means it is itself greater than lmax then we update lmax
                    lmax=height[l];
                }
                l++;
            }
            else{
                if(rmax>height[r]){
                    total+=rmax-height[r];
                }
                else{
                    rmax=height[r];
                }
                r--;
            }
        }
        return total;

    }
};