#include <iostream>
using namespace std;

/*
Definition of doubly linked list:
*/
struct DoublyListNode
{
    int val;
    DoublyListNode *prev;
    DoublyListNode *next;
    DoublyListNode(int data1)
    {
        val = data1;
        prev = NULL;
        next = NULL;
    }
    DoublyListNode(int data1, DoublyListNode *prev1, DoublyListNode *next1)
    {
        val = data1;
        prev = prev1;
        next = next1;
    }
};

class Solution {
public:
    DoublyListNode* deleteHead(DoublyListNode* &head) {
        if (head == NULL) return NULL;
        DoublyListNode* temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        delete temp;
        return head;
    }
};
