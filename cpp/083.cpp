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
        ListNode* deleteDuplicates(ListNode* head) {
            if (head == nullptr) {
                return head;
            }
            ListNode* cur = head;
            while (cur->next != nullptr) {
                if (cur->val != cur->next->val)
                    cur = cur->next;
                else {
                    cur->next = cur->next->next;
                }
            }
            return head;
        }
    };