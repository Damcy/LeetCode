// author: Ian
// create on: 2017-03-26
// email: stmayue@gmail.com
// description: Course Schedule

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
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
        
        while (!qu.empty()) {
            int node = qu.front();
            qu.pop();
            for (int to : graph[node]) {
                --in_degree[to];
                if (in_degree[to] == 0) {
                    qu.push(to);
                }
            }
        }
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] != 0) {
                return false;
            }
        }
        return true;
    }
};