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
        ListNode* swapPairs(ListNode* head) {
            if (!head) return head;
            if (!head->next) return head;
            ListNode* root = new ListNode(0);
            root->next = head;
            ListNode* cur = root;
            while (cur != nullptr) {
                if (!cur->next || !cur->next->next) {
                    break;
                }
                ListNode* next1 = cur->next;
                ListNode* next2 = cur->next->next;
                next1->next = next2->next;
                next2->next = next1;
                cur->next = next2;
                cur = cur->next->next;
            }
            return root->next;
        }
    };