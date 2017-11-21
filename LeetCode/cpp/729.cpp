class MyCalendar {
private:
    map<int, int> _map;
public:
    MyCalendar() {
        _map.clear();
    }

    bool book(int start, int end) {
        map<int,int>::iterator itleft,itright;
        itleft = _map.upper_bound(start);
        itright = _map.lower_bound(end);
        if (itright == _map.begin()) {
            _map[start] = end;
            return true;
        }
        --itleft;
        --itright;
        // cout << start << ", " << end << endl;
        if (_map.empty()) {
            // cout << "empty" << endl;
            _map[start] = end;
        } else {
            // cout << "itleft: " << itleft->first << endl;
            // cout << "itright: " << itright->first << endl;
            if (itleft != _map.end()) {
                // cout << "itleft: " << itleft->second << endl;
                if (start < itleft->second) {
                    return false;
                }
            }
            if (itright != _map.end()) {
                // cout << "itright: " << itright->second << endl;
                if (itright->first >= start) {
                    return false;
                }
            }
            _map[start] = end;
        }
        return true;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
