#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;
        ListNode* next = nullptr;

        int count = 0;
        while (curr) {
            count++;
            curr = curr->next;
        }

        curr = head;
        while (count >= k) {
            curr = prev->next;
            next = curr->next;
            for (int i = 1; i < k; i++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            count -= k;
        }

        return dummy.next;
    }
};
