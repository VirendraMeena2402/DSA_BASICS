#include <iostream>
using namespace std;

/*
Definition of singly linked list:
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

class Solution {
public:
    ListNode* deleteHead(ListNode* &head) {
        if (head == NULL) return NULL;
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
};
