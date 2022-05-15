class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ans = 0;
        sort(special.begin(), special.end());
        for(int i = 0; i < special.size(); ++i) {
            ans = max(ans, special[i] - bottom);
            bottom = special[i] + 1;
        }
        ans = max(ans, top - bottom + 1);
        return ans;
    }
};