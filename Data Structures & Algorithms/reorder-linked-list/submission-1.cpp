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

    ListNode* reverse(ListNode* node)
    {

        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = node;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* getMid(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = fast;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    void reorder(ListNode* h1, ListNode* h2)
    {
        // keep adding chains of h1->h2, until both are nullptr
        while (h2 != nullptr)
        {
            ListNode* n1 = h1->next;
            ListNode* n2 = h2->next;

            h1->next = h2;
            h2->next = n1;

            h1 = n1; h2 = n2;
        }
    }

    void reorderList(ListNode* head) {

        // plan: reverse the second half of the LL, then integrate it to the first half
        // steps:
        // 1. get the mid-node with fast-slow
        // 2. reverse the LL starting from 1 beyond the mid
        // 3. integrate the first half and the reversed second half

        if (!head || !head->next || !head->next->next)
            return;

        ListNode* mid = getMid(head);
        std::cout << "mid has value " << mid->val << std::endl;
        
        ListNode* reverseMe = mid->next;
        mid->next = nullptr;

        // reverse from mid
        ListNode* head2 = reverse(reverseMe);
        std::cout << "head2 has val " << head2->val << std::endl;
        
        // integrate
        reorder(head, head2);
    }
};
