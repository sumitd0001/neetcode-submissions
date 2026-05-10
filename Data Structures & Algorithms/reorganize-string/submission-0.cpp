class Solution {
public:
    string reorganizeString(string s) {
        int cooldown = 1;
        int n = s.size();

        int arr[26] = {0};
        for (char& c : s) arr[c - 'a']++;

        priority_queue<pair<int , char>> pq;
        for (int i = 0; i<26; ++i) if (arr[i]) pq.push({arr[i], i+'a'});

        queue<pair<int, pair<int , char>>> q;
        int pos = 0;
        string str;
        while (!pq.empty() || !q.empty()) {
            while (!q.empty() && q.front().second.first <= pos) {
                pq.push({q.front().first, q.front().second.second});
                q.pop();
            }
            if (!pq.empty()) {
                auto& temp = pq.top();
                str += temp.second;
                if (temp.first > 1) q.push({temp.first - 1, {pos+cooldown+1, temp.second}});
                pos++;
                pq.pop();
            }
            else return "";
        }
        return (str.size() == s.size()) ? str : "";
    }
};