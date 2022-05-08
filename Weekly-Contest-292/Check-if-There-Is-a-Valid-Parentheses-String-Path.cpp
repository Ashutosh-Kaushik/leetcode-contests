class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        vector< vector < vector<int> > > dp;
        const int n = grid.size();
        const int m = grid[0].size();
        dp.resize(n);
        for(int i = 0; i < grid.size(); ++i) {
            dp[i].resize(m);
            for(int j = 0; j < grid[i].size(); ++j) {
                dp[i][j].resize(n + m, 0);
            }
        }
        if(grid[0][0] == ')') return 0;
        dp[0][0][1] = 1;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                for(int k = 0; k < n + m; ++k) {
                    if(grid[i][j] == ')' && k+1 < n + m) {
                        if(i-1 >= 0) dp[i][j][k] |= dp[i-1][j][k+1];
                        if(j-1 >= 0) dp[i][j][k] |= dp[i][j-1][k+1];
                    }
                    else if(grid[i][j] == '(' && k-1 >= 0) {
                        if(i-1 >= 0) dp[i][j][k] |= dp[i-1][j][k-1];
                        if(j-1 >= 0) dp[i][j][k] |= dp[i][j-1][k-1];
                    }
                }
            }
        }
        return dp[n-1][m-1][0];
        
    }
};