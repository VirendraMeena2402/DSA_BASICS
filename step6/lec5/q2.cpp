#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        ListNode* temp = head;
        int len = 1;
        while (temp->next) {
            len++;
            temp = temp->next;
        }

        temp->next = head;
        k = k % len;
        int skip = len - k;

        ListNode* newTail = temp;
        while (skip--) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        return newHead;
    }
};
