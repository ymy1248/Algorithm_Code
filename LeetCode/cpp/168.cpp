class Solution {
public:
    string convertToTitle(int n) {
        unordered_map<int, string> _map;
        _map[0] = "Z";
        _map[1] = "A";
        _map[2] = "B";
        _map[3] = "C";
        _map[4] = "D";
        _map[5] = "E";
        _map[6] = "F";
        _map[7] = "G";
        _map[8] = "H";
        _map[9] = "I";
        _map[10] = "J";
        _map[11] = "K";
        _map[12] = "L";
        _map[13] = "M";
        _map[14] = "N";
        _map[15] = "O";
        _map[16] = "P";
        _map[17] = "Q";
        _map[18] = "R";
        _map[19] = "S";
        _map[20] = "T";
        _map[21] = "U";
        _map[22] = "V";
        _map[23] = "W";
        _map[24] = "X";
        _map[25] = "Y";

        string s = "";
        while (n != 0) {
            int r = n % 26;
            s = _map.find(r)->second + s;
            n /= 26;
            if (r == 0) {
                n -= 1;
            }
        }
        return s;
    }
};
