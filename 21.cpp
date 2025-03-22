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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if (!list1 && !list2) return nullptr;
            ListNode* res = new ListNode(0);
            ListNode* cur = res;
            ListNode* pre = nullptr;
            int t = 0;
            for (ListNode* i1 = list1, *i2 = list2; i1 != nullptr || i2 != nullptr; ) {
                if (i1 != nullptr && i2 != nullptr) {
                    cout << ++t << endl;
                    if ((i1->val) < (i2->val)) {
                        cur->val = i1->val;
                        i1 = i1->next;
                    } else {
                        cur->val = i2->val;
                        i2 = i2->next;
                    }
                } 
                else if (i1 != nullptr) {
                    cur->val = i1->val;
                    i1 = i1->next;
                } else cur->val = i2->val, i2 = i2->next;
                cur->next = new ListNode(0);
                pre = cur;
                cur = cur->next;
            }
            if (pre) pre->next = nullptr;
            return res;
        }
    };