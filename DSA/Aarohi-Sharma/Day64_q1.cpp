class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return buildString(s) == buildString(t);
    }

private:
    string buildString(const string& str) {
        string result = "";
        for (char c : str) {
            if (c == '#') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                result += c;
            }
        }
        return result;
    }
};
