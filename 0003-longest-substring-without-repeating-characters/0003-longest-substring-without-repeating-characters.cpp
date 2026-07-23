class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(s.size()==0) return 0;
        int l=0,r=0;
        int ans=INT_MIN;
        unordered_map<int,int> mp;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(mp[s[l]]);
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};