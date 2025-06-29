#include <iostream>
using namespace std;

/*
Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
    ListNode(int x, ListNode* next1) {
        val = x;
        next = next1;
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};
