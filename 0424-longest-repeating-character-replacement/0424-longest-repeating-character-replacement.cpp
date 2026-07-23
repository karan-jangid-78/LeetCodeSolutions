class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        vector<int> hash(26,0);
        int l=0,r=0;
        int n=s.size();
        int maxfreq=0;
        while(r<n){
            hash[s[r]-'A']++;
            //if the maxlen=5 and mf=3 then 5-3=2 is the last valid condition and if i want a better ans maxlen=6 then 6-3 will also invalid then there is no point to keep the mf=2 because 6-2 will also invalid if maxlen has to be 6 then mf should be 4 it means mf should increase for better maxlen
            maxfreq=max(maxfreq,hash[s[r]-'A']);
            //second optimization using if instead of while
            if((r-l+1)-maxfreq>k){
                hash[s[l]-'A']--;
                maxfreq=0;
                //first optimization 
                // for(int i=0;i<26;i++){
                //     maxfreq=max(maxfreq,hash[i]);
                // }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};