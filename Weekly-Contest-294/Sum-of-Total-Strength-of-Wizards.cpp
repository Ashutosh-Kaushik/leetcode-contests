class Solution {
public:
    int totalStrength(vector<int>& a) {
        
        const int MOD = 1e9 + 7;
        stack< pair<int, int> > st;
        int n = a.size();
        vector<int> r_min(n+1, n+1);
        for(int i = 0; i < n; ++i) {
            while(st.size() && st.top().first > a[i]) {
                r_min[st.top().second] = i+1;
                st.pop();
            }
            st.push({a[i], i});
        }
        while(st.size()) st.pop();
        vector<int> l_min(n+1, 0);
        for(int i = n-1; i >= 0; --i) {
            while(st.size() && st.top().first >= a[i]) {
                l_min[st.top().second] = i+1;
                st.pop();
            }
            st.push({a[i], i});
        }
        
        vector<long long> p_sum(n+1, 0);
        for(int i = 1; i < n+1; ++i) {
            p_sum[i] = (p_sum[i-1] + a[i-1]) % MOD;
        }
        vector<long long> prefix_sum(n+2, 0);
        for(int i = 1; i < n+2; ++i) {
            prefix_sum[i] = p_sum[i-1] + prefix_sum[i-1];
            prefix_sum[i] %= MOD;
        }
        long long ret = 0;
        for(int i = 1; i <= n; ++i) {
            int r = r_min[i-1];
            int l = l_min[i-1];
            l++;
            r--;
            long long sum = (prefix_sum[r+1] - prefix_sum[i] + MOD) % MOD;
            sum *= (i - l + 1);
            sum %= MOD;
            long long neg = (prefix_sum[i] - prefix_sum[l-1] + MOD) % MOD;
            neg *= (r - i + 1);
            neg %= MOD;
            sum = (sum - neg + MOD) % MOD;
            sum *= a[i-1];
            sum %= MOD;
            ret = (ret + sum) % MOD;
        }
        return ret;
    }
};
