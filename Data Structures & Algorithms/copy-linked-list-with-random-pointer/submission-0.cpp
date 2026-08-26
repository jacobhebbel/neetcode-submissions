/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    Node* copyRandomList(Node* head) {
        
        Node* traveller = head;
        std::unordered_map<Node*, Node*> relation;
        while (traveller != nullptr)
        {
            relation[traveller] = new Node(traveller->val);
            traveller = traveller->next;
        }

        Node* newHead = relation[head];
        Node* curr = newHead;
        traveller = head;
        while (traveller != nullptr)
        {
            curr = relation[traveller];

            // setting the next pointer
            if (traveller->next == nullptr)
            {
                curr->next = nullptr;
            } 

            else
            {
                curr->next = relation[traveller->next];
            }

            // setting the random pointer
            if (traveller->random == nullptr)
            {
                curr->random = nullptr;
            }
            else 
            {
                curr->random = relation[traveller->random];
            }

            curr = curr->next;
            traveller = traveller->next;
        }

        return newHead;
    }
};
