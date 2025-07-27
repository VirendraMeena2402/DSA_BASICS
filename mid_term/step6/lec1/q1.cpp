#include <iostream>
using namespace std;

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
    ListNode* insertAtHead(ListNode* &head, int X) {
        ListNode* newNode = new ListNode(X);
        newNode->next = head;
        head = newNode;
        return head;
    }
};
