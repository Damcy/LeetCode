// author: Ian
// create on: 2017-02-24
// email: stmayue@gmail.com
// description: Clone Graph

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return NULL;
        }
        queue<UndirectedGraphNode*> to_visit;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> old_new;
        unordered_set<int> visited;
        to_visit.push(node);
        visited.insert(node->label);
        while (!to_visit.empty()) {
            UndirectedGraphNode* temp = to_visit.front();
            to_visit.pop();
            UndirectedGraphNode* new_graph_node = NULL;
            if (old_new.find(temp) == old_new.end()) {
                UndirectedGraphNode* temp_new = new UndirectedGraphNode(temp->label);
                old_new[temp] = temp_new;
                new_graph_node = temp_new;
            } else {
                new_graph_node = old_new[temp];
            }
            for (int i = 0; i < temp->neighbors.size(); ++i) {
                UndirectedGraphNode *temp_nei = temp->neighbors[i];
                UndirectedGraphNode *new_graph_nei = NULL;
                if (old_new.find(temp_nei) == old_new.end()) {
                    UndirectedGraphNode* temp_new = new UndirectedGraphNode(temp_nei->label);
                    old_new[temp_nei] = temp_new;
                    new_graph_nei = temp_new;
                } else {
                    new_graph_nei = old_new[temp_nei];
                }
                new_graph_node->neighbors.push_back(new_graph_nei);
                if (visited.find(temp_nei->label) == visited.end()) {
                    to_visit.push(temp_nei);
                    visited.insert(temp_nei->label);
                }
            }
        }
        return old_new[node];
    }
};