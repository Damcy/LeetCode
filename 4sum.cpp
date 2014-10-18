class Solution {
	public:
        vector<vector<int> > fourSum(vector<int> &num, int target) {
            vector<vector<int> > result;
            int size = num.size();
            if (size < 4) {
                    return result;
            }
            // sort num list
            sort(num.begin(), num.end());
            int keep_pre_1 = num[0] - 1;
            for (int pos_1 = 0; pos_1 < size - 3; ++pos_1) {
                if (num[pos_1] == keep_pre_1) {
                    continue;
                }
                int keep_pre_2 = num[pos_1] - 1;
                for (int pos_2 = pos_1 + 1; pos_2 < size - 2; ++pos_2) {
                    if (num[pos_2] == keep_pre_2) {
                        continue;
                    }
                    int pos_3 = pos_2 + 1;
                    int pos_4 = size - 1;
                    int keep_pre_3 = num[pos_3] - 1;
                    while(pos_3 < pos_4) {
                        if (num[pos_3] == keep_pre_3 || num[pos_1] + num[pos_2] + num[pos_3] + num[pos_4] < target) {
                            ++pos_3;
                        }
                        else if (num[pos_1] + num[pos_2] + num[pos_3] + num[pos_4] == target) {
                            vector<int> tmp;
                            tmp.push_back(num[pos_1]);
                            tmp.push_back(num[pos_2]);
                            tmp.push_back(num[pos_3]);
                            tmp.push_back(num[pos_4]);
                            result.push_back(tmp);
                            keep_pre_3 = num[pos_3];
                            ++pos_3;
                        }
                        else{
                            --pos_4;
                        }
                    }
                    keep_pre_2 = num[pos_2];
                }
                keep_pre_1 = num[pos_1];
            }
            return result;
        }
};
