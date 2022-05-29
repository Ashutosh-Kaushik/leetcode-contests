class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int ar) {
        vector<int> x;
        for(int i = 0; i < c.size(); ++i) {
            x.push_back(c[i] - r[i]);
        }
        sort(x.begin(), x.end());
        int ans = 0;
        for(int i = 0; i < x.size() && x[i] <= ar; ++i) {
            ans++;
            ar -= x[i];
        }
        return ans;
    }
};
