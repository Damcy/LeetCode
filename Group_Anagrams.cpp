// author: Ian
// create on: 2015-12-17
// description: LeetCode Group Anagrams

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        vector<vector<string> > groupAnagrams(vector<string>& strs) {
            // construct a map to classify strs
            // key is sorted str
            // value are elements in strs
            map<string, vector<string> > hmap;
            for (int i = 0; i < strs.size(); ++i) {
                string key = strs[i];
                // fine the key
                sort(key.begin(), key.end());
                map<string, vector<string> >::iterator it = hmap.find(key);
                // then insert it to the map according to its key
                if (it != hmap.end()) {
                    it->second.push_back(strs[i]);
                } else {
                    vector<string> temp;
                    temp.push_back(strs[i]);
                    hmap.insert(pair<string, vector<string> >(key, temp));
                }
            }

            // construct result
            vector<vector<string> > res;
            for (map<string, vector<string> >::iterator it = hmap.begin();
                    it != hmap.end(); ++it) {
                // sort values in the same key
                sort(it->second.begin(), it->second.end());
                res.push_back(it->second);
            }

            return res;
        }
};
