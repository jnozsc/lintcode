/*
Reverse a linked list.
Example
For linked list 1->2->3, the reversed linked list is 3->2->1
*/
#include "lintcode.h"

using namespace std;

/**
 * Definition of ListNode
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
  public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode* reverse(ListNode* head) {
        // write your code here
        if (!head || !head->next) {
            return head;
        }
        ListNode* first = head;
        ListNode* second = head->next;
        first -> next = NULL;
        while (second) {
            ListNode* nextSecond = second->next;
            second->next = first;
            first = second;
            second = nextSecond;
        }
        return first;

    }
};
