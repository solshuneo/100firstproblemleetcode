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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* res = new ListNode(0);
            ListNode* cur = res;
            int remain = 0;
            for (ListNode* a = l1, *b = l2; a != nullptr || b != nullptr; ) {
                if (a) cur->val += a->val;
                if (b) cur->val += b->val;
                cur->val += remain;
                remain = cur->val / 10;
                cur->val %= 10;
    
                if (a) a = a->next;
                if (b) b = b->next;
                if (a || b) {
                    cur->next = new ListNode(0);
                    cur = cur->next;
                }
            }
            if (remain == 1) {
                cur->next = new ListNode(1);
            } 
            return res;
        }
    };