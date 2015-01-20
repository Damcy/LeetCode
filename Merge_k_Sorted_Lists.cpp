// author: damcy<stmayue@gmail.com>
// create on: 2014-11-10

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
    ListNode() : val(0), next(NULL) {}
};

bool cmp(const ListNode* a, const ListNode* b) {
    return a->val > b->val;
};

class Solution {      
    public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return NULL;
        }
        vector<ListNode *> my_heap;
        for (vector<ListNode *>::iterator it = lists.begin(); it != lists.end(); ++it) {
            if( *it != NULL ) {
                my_heap.push_back(*it);
            }
        }
        std::make_heap(my_heap.begin(), my_heap.end(), cmp);
        ListNode *head = NULL;
        ListNode *res_tail = NULL;
        ListNode *tmp = NULL;
        while(!my_heap.empty()) {
            tmp = my_heap.front();
            if(head == NULL) {
                head = tmp;
                res_tail = head;
            }
            else {
                res_tail->next = tmp;
                res_tail = tmp;
            }
            std::pop_heap(my_heap.begin(), my_heap.end(), cmp);
            my_heap.pop_back();
            if(tmp->next != NULL) {
                my_heap.push_back(tmp->next);
                std::push_heap(my_heap.begin(), my_heap.end(), cmp);
            }
        }
        return head;
    }
};
