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
    DoublyListNode* deleteTarget(DoublyListNode* head, int target) {
        while (head && head->val == target) {
            head = head->next;
            if (head) head->prev = NULL;
        }

        DoublyListNode* curr = head;

        while (curr) {
            if (curr->val == target) {
                if (curr->prev) curr->prev->next = curr->next;
                if (curr->next) curr->next->prev = curr->prev;
            }
            curr = curr->next;
        }

        return head;
    }
};
