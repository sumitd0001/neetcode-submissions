class Solution {
public:

    string encode(vector<string>& strs) {
        string str;
        for (const auto& s : strs) {
            str += to_string(s.size()) + "#" + s;
        }
        return str;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> res;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++;
            int l = std::stoi(s.substr(i, j-i));
            i = j + 1;
            j = i + l;
            res.push_back(s.substr(i, l));
             i = j;
        }
        return res;
    }
};
