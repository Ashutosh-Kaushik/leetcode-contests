class Solution {
public:
    int minimumLines(vector<vector<int>>& sp) {
        sort(sp.begin(), sp.end());
        pair<int,int> prev = {-1,-1};
        int ans = 0;
        for(int i = 0; i+1 < sp.size(); ++i) {
            int y = sp[i+1][1] - sp[i][1];
            int x = sp[i+1][0] - sp[i][0];
            int cm = __gcd(x, y);
            x /= cm;
            y /= cm;
            pair<int,int> cur = {y, x};
            if(cur != prev) {
                ans++;
                prev = cur;
            }
            
        }
        return ans;
    }
};
