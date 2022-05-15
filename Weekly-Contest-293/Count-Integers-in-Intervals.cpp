class CountIntervals {
public:
    set< pair<int, int> > s;
    int cnt = 0;
    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        auto it = s.lower_bound(make_pair(left, -1));
        int cur_sum = 0;
        while(it != s.end() && (*it).second <= right) {
            left= min(left, (*it).second);
            right = max(right, (*it).first);
            cur_sum += (*it).first - (*it).second + 1;
            it = s.erase(it);
        }
        cnt -= cur_sum;
        cnt += (right - left + 1);
        s.insert(make_pair(right, left));
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */