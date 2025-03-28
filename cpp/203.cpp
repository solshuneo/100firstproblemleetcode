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
        ListNode* removeElements(ListNode* head, int val) {
            vector<int> res;
            while (head) {
                if (head->val != val) res.emplace_back(head->val);
                head = head->next;
            }
            ListNode* ans;
            if (!res.empty()) {
                ans = new ListNode(0);
                ListNode* cur = ans;
                int n = res.size();
                for (int i = 0; i < n; ++i) {
                    cur->val = res[i];
                    if (i < n - 1) cur->next = new ListNode(0);
                    cur = cur->next;
                }
            }
            return ans;
        }
    };