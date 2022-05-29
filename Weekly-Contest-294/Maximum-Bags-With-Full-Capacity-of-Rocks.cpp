class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == letter) cnt++;
        }
        int tot = s.length();
        int sum = cnt * 100;
        return (sum / tot);
    }
};
