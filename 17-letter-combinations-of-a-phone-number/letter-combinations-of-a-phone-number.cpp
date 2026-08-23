
    class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans = {""};

        for (char digit : digits) {
            vector<string> temp;

            for (string s : ans) {
                for (char c : mp[digit - '0']) {
                    temp.push_back(s + c);
                }
            }

            ans = temp;
        }

        return ans;
    }
};