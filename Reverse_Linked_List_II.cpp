/*
Reverse a linked list from position m to n.
Note
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
Example
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.
*/
#include "lintcode.h"

using namespace std;

/**
 * Definition of singly-linked-list:
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
  public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write your code here
        if (m == n) {
            return head;
        }
        int index = 0;
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* current = dummyNode;
        ListNode* previous = new ListNode(0);;
        ListNode* tail = new ListNode(0);;
        while (current) {
            if (index == m - 1) {
                previous = current;
            }
            if (index == n) {
                tail = current;
            }
            current = current->next;
            index++;
        }
        reverseFromTo(previous, tail);
        return dummyNode->next;
    }

    void reverseFromTo(ListNode* pre, ListNode* end) {
        ListNode* first = pre->next;
        ListNode* second = pre->next->next;
        first->next = end-> next;
        while (second != end) {
            ListNode* new_second = second->next;
            second->next = first;
            first = second;
            second = new_second;
        }
        pre->next = end;
        second->next = first;
    }
};
