class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;

        for (string &word : words) {
            string temp = "";

            for (char ch : word) {
                if (ch == separator) {
                    if (!temp.empty()) {
                        ans.push_back(temp);
                        temp = "";
                    }
                } else {
                    temp += ch;
                }
            }

            if (!temp.empty())
                ans.push_back(temp);
        }

        return ans;
    }
};
