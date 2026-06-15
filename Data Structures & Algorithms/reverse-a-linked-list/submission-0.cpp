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
        if(head==NULL){
            return head;
        }
        ListNode* curr=head;
        ListNode* nex=curr->next;
        ListNode* prev=NULL;
        while(nex){
            curr->next=prev;
            ListNode* temp= nex->next;
            nex->next=curr;
            prev=curr;
            curr=nex;
            nex=temp;
        }
        return curr;
    }
};
