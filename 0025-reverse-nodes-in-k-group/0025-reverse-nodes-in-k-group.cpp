/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next = NULL;

        while(cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp)
        {
            ListNode* start = temp;

            for(int i = 0 ;i<k-1 && temp ; i++)
            {
                temp = temp->next;
            }

            if(!temp)
            {
                if(prev) prev->next = start;
                break;
            }

            ListNode* nextNode = temp->next;
            temp->next = NULL;
            ListNode* newHead = reverseList(start);

            if(head==start) head = newHead;
            else prev->next = newHead;

            prev = start;
            temp = nextNode;
        }

        return head;
    }
};