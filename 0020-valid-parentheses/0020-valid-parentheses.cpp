class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char> st;
        int i=0,count=0;
        while(i<n){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                count++;
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
               if(s[i]==')'&&st.top()=='('||s[i]=='}'&&st.top()=='{'||s[i]==']'&&st.top()=='['){
                    count--;
                    st.pop();
                }
               else  st.push(s[i]);
            }
            i++;
        }
        return count==0?true:false;
    }
};