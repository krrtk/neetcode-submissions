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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp=head;
        int len=0;
        while(tmp){
            tmp=tmp->next;
            len++;
        }
        len-=n;
        tmp=head;
        int c=0;
        ListNode* prev=NULL;
        cout<<len;
        while(tmp){
            if(c==len){
                if(c==0){
                    head=head->next;
                    break;
                }
                prev->next=tmp->next;
            }
            prev=tmp;
            tmp=tmp->next;
            c++;
        }
        return head;
    }
};
