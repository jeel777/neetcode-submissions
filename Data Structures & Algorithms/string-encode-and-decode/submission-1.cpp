class Solution {
public:
    string encode(vector<string>& strs) {
        string ans = "";

        for (int i = 0; i < strs.size(); i++) {
            ans += to_string(strs[i].size());
            ans += "#";
            ans += strs[i];
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i = 0;

        while (i < s.size()) {

            int j = i;

            // Find '#'
            while (s[j] != '#') {
                j++;
            }

            // Get length
            int len = stoi(s.substr(i, j - i));

            // Move past '#'
            j++;

            // Take exactly len characters
            string temp = s.substr(j, len);

            ans.push_back(temp);

            // Move to next encoded string
            i = j + len;
        }

        return ans;
    }
};