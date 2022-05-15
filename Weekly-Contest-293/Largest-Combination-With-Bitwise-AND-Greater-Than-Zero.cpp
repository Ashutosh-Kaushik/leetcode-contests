class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> cnt(25, 0);
        for(int i = 0; i < candidates.size(); ++i) {
            for(int j = 0; j < 25; ++j) {
                long long num = (1ll << j);
                if(num & candidates[i]) {
                    cnt[j]++;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 25; ++i) {
            ans = max(ans, cnt[i]);
        }
        return ans;
    }
};