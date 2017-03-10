// author: Ian
// create on: 2017-03-10
// email: stmayue@gmail.com
// description: Compare Version Numbers


class Solution {
public:
    int compareVersion(string version1, string version2) {
        if (version1.size() == 0 || version2.size() == 0) {
            return version1.size() > 0 ? 1 : -1;
        }
        int len1 = version1.size();
        int len2 = version2.size();
        int index1 = 0;
        int index2 = 0;
        while (index1 < len1 || index2 < len2) {
            int v1 = 0;
            int v2 = 0;
            while (index1 < len1) {
                if (version1[index1] == '.') {
                    ++index1;
                    break;
                } else {
                    v1 = v1 * 10 + (version1[index1] - '0');
                    ++index1;
                }
            }
            while (index2 < len2) {
                if (version2[index2] == '.') {
                    ++index2;
                    break;
                } else {
                    v2 = v2 * 10 + (version2[index2] - '0');
                    ++index2;
                }
            }
            if (v1 != v2) {
                return v1 > v2 ? 1 : -1;
            }
        }
        return 0;
    }
};