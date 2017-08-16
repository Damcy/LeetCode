// author: Ian
// create on: 2017-07-30
// email: stmayue@gmail.com
// description: Course Schedule II

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>(0));
        vector<int> in_degree(numCourses, 0);
        for (pair<int, int> edge : prerequisites) {
            ++in_degree[edge.first];
            graph[edge.second].push_back(edge.first);
        }
        queue<int> qu;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) {
                qu.push(i);
            }
        }

        vector<int> res;
        while (!qu.empty()) {
            int node = qu.front();
            qu.pop();
            res.push_back(node);
            for (int to : graph[node]) {
                --in_degree[to];
                if (in_degree[to] == 0) {
                    qu.push(to);
                }
            }
        }
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] != 0) {
                vector<int> tmp;
                return tmp;
            }
            if (find(res.begin(), res.end(), i) != res.end()) {
                res.push_back(i);
            }
        }
        return res;
    }
};