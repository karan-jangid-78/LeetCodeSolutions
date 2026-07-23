class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        vector<int> hash(256,0);
        int l=0,r=0;
        int n=s.size();
        int maxfreq=0;
        while(r<n){
            hash[s[r]]++;
            maxfreq=max(maxfreq,hash[s[r]]);
            while((r-l+1)-maxfreq>k){
                hash[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};