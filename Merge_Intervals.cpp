/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        // sort vector
        vector<Interval> res;
        int vec_size = intervals.size();

        if (vec_size == 0) return res;
        sort(intervals.begin(), intervals.end(), cmp);

        // construct result
        int left = intervals[0].start, right = intervals[0].end;
        for (int i = 0; i < vec_size; ++i) {
            // cout << left << " " << right << endl;
            if(right >= intervals[i].end) {
                continue;
            } else if (right >= intervals[i].start) {
                right = intervals[i].end;
            } else {
                Interval tmp(left, right);
                res.push_back(tmp);
                left = intervals[i].start;
                right = intervals[i].end;
            }
        }
        Interval tmp(left, right);
        res.push_back(tmp);
        return res;
    }
};