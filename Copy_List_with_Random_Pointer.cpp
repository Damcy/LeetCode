// author: Ian
// create on: 2017-02-24
// email: stmayue@gmail.com
// description: Copy List with Random Pointer

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) {
            return NULL;
        }
        // construct double length list
        RandomListNode* cur = head;
        while (cur) {
            RandomListNode* new_node = new RandomListNode(cur->label);
            new_node->next = cur->next;
            new_node->random = cur->random;
            cur->next = new_node;
            cur = new_node->next;
        }
        // fix new node's random
        cur = head->next;
        while (cur) {
            if (cur->random) {
                cur->random = cur->random->next;
            }
            if (cur->next == NULL) {
                cur = NULL;
            } else {
                cur = cur->next->next;
            }
        }
        // divide into two list
        RandomListNode* res = head->next;
        cur = head->next;
        while (head) {
            head->next = cur->next;
            if (cur->next) {
                cur->next = cur->next->next;
            }
            head = head->next;
            cur = cur->next;
        }
        return res;
    }
};