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
        
        ListNode* curr = head;
        if (!curr) return curr;

        ListNode* next = curr->next;
        ListNode* prev = nullptr;

        while (next != nullptr)
        {
            
            // steps to reverse a linkedList
            // take the next 
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;

        }

        curr->next = prev;
        return curr;
    }
};
