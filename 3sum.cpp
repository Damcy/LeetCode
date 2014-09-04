class Solution {
	public:
            
            vector<vector<int> > threeSum(vector<int> &num) {
                    vector<vector<int> > result;
                    int size = num.size();
                    if (size < 3) {
                            return result;
                    }
                    
                    sort(num.begin(), num.end());
                    int push_pos = 0;
                    int keep_pre = num[0] - 1;
                    for(int i = 1; i < size - 1; ++i) {
                        int pos_begin = 0, pos_end = size - 1;
                        if(num[i] == keep_pre) {
                            pos_begin = i - 1;
                        }
                        while(pos_begin < i && pos_end > i && pos_begin < pos_end) {
                            if(num[pos_begin] + num[i] + num[pos_end] < 0) {
                                ++pos_begin;
                            }
                            else if(num[pos_begin] + num[i] + num[pos_end] > 0) {
                                --pos_end;
                            }
                            else{
                                if(pos_begin != i && pos_end != i){
                                    vector<int> tmp;
                                    tmp.push_back(num[pos_begin]);
                                    tmp.push_back(num[i]);
                                    tmp.push_back(num[pos_end]);
                                    if(push_pos == 0 || tmp != result[push_pos-1]) {
                                        result.push_back(tmp);
                                        ++push_pos;
                                    }
                                    ++pos_begin;
                                    --pos_end;
                                }
                            }
                        }
                        keep_pre = num[i];
                    }
                    return result;
            }
};
