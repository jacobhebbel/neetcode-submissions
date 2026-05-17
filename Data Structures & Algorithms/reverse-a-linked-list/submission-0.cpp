/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    ListNode* reverseList(ListNode* head) {

        ListNode * curr = head;
        ListNode * next = head;
        ListNode * prev = nullptr;
        while (next != nullptr) {

            cout << curr->val << endl;    
            next = curr->next;  // track the list's next element with next
            curr->next = prev;  // change this node's next to the previous node
            prev = curr;        // update the prev pointer to the current node
            curr = next;        // update the curr pointer to the next node
        
        }

        return prev;

        // next is null, and curr is 
    }
};
