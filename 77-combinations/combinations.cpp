#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;

        auto backtrack = [&](auto self, int prev, vector<int> curr) -> void {
            if (curr.size() == k) {
                res.push_back(curr);
                return;
            }

            for (int x=prev+1; x<=n; x++) {
                curr.push_back(x);
                self(self, x, curr);
                curr.pop_back();
            }
            return;
        };

        vector<int> curr;
        backtrack(backtrack, 0, curr);
        return res;
    }
};