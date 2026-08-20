
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        for(char ch : s) {
            mp[ch]++;
        }

        priority_queue<pair<int, char>> maxh;

        for(auto it : mp) {
            maxh.push({it.second, it.first});
        }

        string ans = "";

        while(!maxh.empty()) {
            int freq = maxh.top().first;
            char ch = maxh.top().second;
            maxh.pop();

            while(freq--) {
                ans += ch;
            }
        }

        return ans;
    }
};