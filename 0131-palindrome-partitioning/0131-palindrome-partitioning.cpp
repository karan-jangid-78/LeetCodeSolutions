class Solution {
public:
vector<vector<string>> result;
vector<string> ans;
void solve(string &s,int index){
    if(index==s.size()){
        result.push_back(ans);
        return;
    }
    for(int i=index;i<s.size();i++){
        if(ispalindrome(s,index,i)==true){
            ans.push_back(s.substr(index,i-index+1));
            solve(s,i+1);
            ans.pop_back();
        }
    }
}
bool ispalindrome(string &s,int index,int i){
    while(index<=i){
        if(s[index++]!=s[i--]) return false;
    }
    return true;
}
    vector<vector<string>> partition(string s) {
        solve(s,0);
        return result;
    }
};