class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> temp(numbers);
        vector<int> result;
        sort(temp.begin(), temp.end());
        int a = 0, b = temp.size() - 1;
        while(a < temp.size() && b > -1 && a < b) {
        	if(temp[a] + temp[b] == target) {
        		vector<int>::iterator it_a = find(numbers.begin(), numbers.end(), temp[a]);
                        vector<int>::iterator it_b;
                        if(temp[a] == temp[b]) {
                            it_b = find(it_a + 1, numbers.end(), temp[b]);
                        }
                        else {
                            it_b = find(numbers.begin(), numbers.end(), temp[b]);
                        }
                        int pos_a = it_a - numbers.begin() + 1;
                        int pos_b = it_b - numbers.begin() + 1;
                        if(pos_a > pos_b) {
                            cout << temp[a] << temp[b] << endl;
                            cout << numbers[pos_b] << numbers[pos_a] << endl;
                            result.push_back(pos_b);
                            result.push_back(pos_a);
                        }
                        else {
                            result.push_back(pos_a);
                            result.push_back(pos_b);
                        }
                        break;
        	}
        	else if (temp[a] + temp[b] > target) {
        		--b;
        	}
        	else {
        		++a;
        	}
        }
        return result;
    }
};
