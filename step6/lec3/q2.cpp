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
    // Iterative method
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    // Recursive method
    ListNode* reverseListRecursive(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverseListRecursive(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};
