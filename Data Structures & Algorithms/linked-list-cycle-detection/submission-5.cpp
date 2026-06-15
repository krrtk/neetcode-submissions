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
    bool hasCycle(ListNode* head) {
        if(head==NULL){
            return false;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        if(fast){
            fast=fast->next;
        }
        else{
            return false;
        }
        while(slow && fast){
            if(slow==fast){
                return true;
            }
            else{
                fast=fast->next;
                if(fast){
                    fast=fast->next;
                }
                else{
                    return false;
                }
                slow=slow->next;
            }
        } 
        return false;
    }
};
