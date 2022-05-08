class Solution {
public:
    int countTexts(string s) {
        vector<int> x(10, 3);
        const int mod = 1e9 + 7;
        x[7] = 4;
        x[9] = 4;
        int n = s.length();
        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= x[s[i-1]-'0'] && j <= i && s[i-j] == s[i-1] ; ++j) {
                dp[i] += dp[i-j];
                dp[i] %= mod;
            }
        }
        return dp[n];
    }
};