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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if (l1 == nullptr and l2 == nullptr) return nullptr;

        ListNode* sentinel = new ListNode();
        ListNode* curr = sentinel;
        
        bool apply_carry = false; 
        while (l1 != nullptr || l2 != nullptr || apply_carry)
        {
            int sum = 0;
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            };
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            if (apply_carry)
            {
                sum += 1;
            }

            apply_carry = sum > 9;
            sum %= 10;
            curr->next = new ListNode(sum);
            curr = curr->next;
        }

        ListNode* head = sentinel->next;
        delete sentinel;
        return head;
    }
};
