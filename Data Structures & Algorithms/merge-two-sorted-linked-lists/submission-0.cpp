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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* c1 = list1;
        ListNode* c2 = list2;
        ListNode* return_me = nullptr;

        // when both exist, start the list
        // at the bigger list node
        if (c1 && c2) 
        {    
            int v1 = c1->val, v2 = c2->val;

            // c1 starts the list
            if (v1 < v2) 
            {
                return_me = c1;
                c1 = c1->next;
            }

            // c2 starts the list
            else 
            {
                return_me = c2;
                c2 = c2->next;
            }
        }

        // return c1 if c2 doesn't exist
        else if (c1)
        {
            return c1;
        }

        // return c2 if c1 doesn't exist
        else 
        {
            return c2;
        }

        // while both pointers are valid
        // take the bigger and increment that pointer
        ListNode* merged = return_me;
        while (c1 && c2)
        {

            int v1 = c1->val, v2 = c2->val;
            if (v1 < v2) 
            {
                merged->next = c1;
                c1 = c1->next;

            } 
            else
            {
                merged->next = c2;
                c2 = c2->next;
            }

            merged = merged->next;

        }

        // assign whichever remaining list 
        // to merged and return
        if (c1) merged->next = c1;
        else merged->next = c2;
        return return_me;
    }
};
