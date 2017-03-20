// author: Ian
// create on: 2017-03-20
// email: stmayue@gmail.com
// description: Largest Number

bool cmp(string s1, string s2) {
    return s1 + s2 > s2 + s2;
}


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) {
            return "";
        }
        vector<string> str(nums.size());
        stringstream ss;
        for (int i = 0; i < nums.size(); ++i) {
            ss << nums[i];
            ss >> str[i];
            ss.clear();
        }
        sort(str.begin(), str.end(), cmp);
        string res;
        for (string i : str) {
            res += i;
        }
        int pos = 0;
        while (res[pos] == '0' && pos != res.size() - 1) {
            ++pos;
        }
        return res.substr(pos);
    }
};