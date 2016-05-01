class Solution {
public:
    string simplifyPath(string path) {
        vector<string> sub_path;
        int s_len = path.length();
        string tmp_path = "";
        for (int i = 0; i < s_len; ++i) {
            if (path[i] == '/') {
                if (tmp_path != "") {
                    if (tmp_path == ".") {
                        tmp_path = "";
                        continue;
                    } else if (tmp_path == "..") {
                        if (!sub_path.empty()) {
                            sub_path.pop_back();
                        } else {
                            // /../ is / not /..
                            // sub_path.push_back(tmp_path);
                        }
                    } else {
                        sub_path.push_back(tmp_path);
                    }
                    tmp_path = "" + path[i];
                } else {
                    tmp_path = "";
                }
            } else {
                tmp_path = tmp_path + path[i];
            }
        }
        if (tmp_path != "" && tmp_path != "." && tmp_path != "..") {
            sub_path.push_back(tmp_path);
        } else if (tmp_path == ".." && !sub_path.empty()) {
            sub_path.pop_back();
        }
        if (sub_path.size() == 0) {
            return "/";
        } else {
            string res = "";
            for (int i = 0; i < sub_path.size(); ++i) {
                res = res + "/" + sub_path[i];
            }
            return res;
        }
    }
};