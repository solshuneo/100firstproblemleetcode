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
        ListNode* reverseList(ListNode* head) {
            if (head == nullptr) return head;
            vector<int> value;
            while (head) {
                value.emplace_back(head->val);
                head = head->next;
            }
            reverse(value.begin(), value.end());
            ListNode *rev = new ListNode(0);
            ListNode *cur = rev;
            for (int i = 0; i < value.size(); ++i) {
                cur->next = new ListNode(value[i]);
                cur = cur->next;
            }
            return rev->next;
        }
    };