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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int vec_size = intervals.size();
        int insert_mark = 0;
        for(int i = 0; i < vec_size; ++i) {
            if (insert_mark) {
                res.push_back(intervals[i]);
                continue;
            }

            if (newInterval.end < intervals[i].start) {
                // newInterval is not overlaps intervals[i]
                res.push_back(newInterval);
                res.push_back(intervals[i]);
                insert_mark = 1;
            } else if (newInterval.end >= intervals[i].start && newInterval.start <= intervals[i].end) {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            } else {
                // newIntervals.start > intervals[i].end
                res.push_back(intervals[i]);
            }
        }
        if (!insert_mark) {
            res.push_back(newInterval);
        }
        return res;
    }
};