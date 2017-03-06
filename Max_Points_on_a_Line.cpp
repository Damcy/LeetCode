// author: Ian
// create on: 2017-03-06
// email: stmayue@gmail.com
// description: Max Points on a Line

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.empty()) {
            return 0;
        }
        int point_num = points.size();
        unordered_map<long double, int> cnt;
        int max_res = 1;
        for (int i = 0; i < point_num; ++i) {
            // clear record
            int vertical_line = 0;
            int origin = 0;
            cnt.clear();
            for (int j = 0; j < point_num; ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++origin;
                } else if (points[i].x - points[j].x == 0) {
                    ++vertical_line;
                } else {
                    long double gradient = (long double)(points[i].y - points[j].y) / (points[i].x - points[j].x);
                    cnt[gradient] += 1;
                }
            }
            for (unordered_map<long double, int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
                max_res = max(max_res, it->second + origin);
            }
            max_res = max(max_res, vertical_line + origin);
        }
        return max_res;
    }
};