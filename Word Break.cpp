class Solution {
public:
    vector<int> dp;
    
    bool helper(string s , unordered_set<string> &st , int index) {
        if(index>=s.length())
            return 1;
        if(dp[index]!=-1)
            return dp[index];
        string temp = "";
        for(int i=index;i<s.length();i++){
            temp += s[i];
            if(st.find(temp)!=st.end()){
                if(helper(s,st,i+1))
                    return dp[index] = 1;
            }
                
        }
        return dp[index] = 0;        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        dp.assign(n,-1);
        unordered_set<string> st(wordDict.begin() , wordDict.end());
        return helper(s,st,0);
    }
};
