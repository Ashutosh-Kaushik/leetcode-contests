class Solution {
public:
    string largestGoodInteger(string s) {
        string ans = "";
        int cur = -1;
        for(int i = 0; i+2 < s.length(); ++i) {
            if(s[i] == s[i+1] && s[i+1] == s[i+2]) {
                int x = s[i] - '0';
                cur = max(cur, x);
            }
        }
        if(cur == -1) return ans;
        for(int i = 0; i < 3; ++i) {
            ans.push_back('0' + cur);
        }
        return ans;
    }
};