class Solution {
public:
int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n=arr.size();
        int totalsum=0;
        for(int i=0;i<n;i++) totalsum+=arr[i];
        if(totalsum-diff<0 || (totalsum-diff)%2==1) return 0;
        int target=(totalsum-diff)/2;
        vector<int> prev(target+1,0), cur(target+1,0);
        for (int t = 0; t <= target; t++) {
			if (t == 0) {
				if (arr[0] == 0)
					prev[t] = 2;
				else
					prev[t] = 1;
			}
			else {
				if (arr[0] == t)
					prev[t] = 1;
				else
					prev[t] = 0;
			}
		}
		for (int index = 1; index < n; index++) {
			for (int t = 0; t <= target; t++) {
				int nottake = prev[t];
				int take = 0;
				if (arr[index] <= t) {
					take = prev[t - arr[index]];
				}
				cur[t] = take + nottake;
			}
			prev=cur;
		}
        return prev[target];
}
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);
    }
};