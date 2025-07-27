#include <iostream>
using namespace std;

struct DoublyListNode {
    int val;
    DoublyListNode* prev;
    DoublyListNode* next;
    DoublyListNode(int x) {
        val = x;
        prev = NULL;
        next = NULL;
    }
};

class Solution {
public:
    DoublyListNode* removeDuplicates(DoublyListNode* head) {
        if (!head) return head;

        DoublyListNode* curr = head;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                DoublyListNode* dup = curr->next;
                curr->next = dup->next;
                if (dup->next) dup->next->prev = curr;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};
