class Solution {
public:
    
    vector<string> removeAnagrams(vector<string>& words) {
        auto is_anagram = [](string a, string b) {
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            
            if(a == b) return true;
            return false;
        };
        while(true) {
            bool ok = false;
            for(int i = 1; i < words.size(); ++i) {
                if(is_anagram(words[i-1], words[i]))  {
                    ok = true;
                    auto del = next(words.begin(), i);
                    words.erase(del);
                    break;
                }
            }
            if(!ok) break;
        }
        return words;
    }
};