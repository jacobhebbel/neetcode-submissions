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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if (!head) return head;

        int list_size = 1;
        ListNode* traveller = head;
        while (traveller->next != nullptr)
        {
            traveller = traveller->next;
            list_size++;
        }
        
        if (list_size == 1) return nullptr;

        int idx_to_remove = list_size - n;
        if (idx_to_remove == 0)
        {
            return head->next;
        }
        // [8], 2

        ListNode* prev = head;
        ListNode* curr = head;
        while (idx_to_remove--)
        {
            prev = curr;
            curr = curr->next;
        }

        ListNode* next = curr->next;
        prev->next = next;

        return head;
    }
};
