class Solution {
   public:
    int solve(int index, string s, int n,vector<int>&dp) {

        if (index == n) return 1;
        int one=0,two=0;

        if(dp[index]!=-1)return dp[index];

        if (s[index] > '0') {
            one += solve(index + 1, s, n,dp);
        }

        if (index < n - 1 && s[index] > '0') {
            int temp=(s[index]-'0')*10+(s[index+1]-'0');
            
            if(temp<27){
            two += solve(index + 2, s, n,dp);
            }
        }

        return dp[index] = one + two;
    }
    int numDecodings(string s) {
        int n = s.size();
        
        vector<int>dp(n,-1);

        if(s[0]=='0')return 0;
        return solve(0,s,n,dp);
    }
};
