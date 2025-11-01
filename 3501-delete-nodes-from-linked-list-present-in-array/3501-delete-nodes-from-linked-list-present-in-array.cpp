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
    ListNode* modifiedList(vector<int>& elements, ListNode* head) {
        unordered_set<int> elementSet(elements.begin(), elements.end());
        ListNode* tempHead = new ListNode(0);
        tempHead->next = head;
        ListNode* current = tempHead;
        
        while (current->next) {
            if (elementSet.find(current->next->val) != elementSet.end()) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        
        return tempHead->next;
    }
};