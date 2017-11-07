class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for (size_t i = 0; i < wordDict.size(); ++i) {
            set.insert(wordDict[i]);
        }
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(set.find(word)!= set.end())
                    {
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};
