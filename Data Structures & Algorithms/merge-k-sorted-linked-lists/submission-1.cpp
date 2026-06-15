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
    ListNode* merge(ListNode* &node, ListNode* &lst){
        ListNode dummy(0);
        ListNode* tt=&dummy;
        while(node && lst){
            if(node->val <= lst->val){
                tt->next=node;
                node=node->next;
            }
            else{
                tt->next=lst;
                lst=lst->next;
            }
            tt=tt->next;
        }
        if(node){
            tt->next=node;
        }
        if(lst){
            tt->next=lst;
        }
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* node=nullptr;
        for(int i=0;i<lists.size();i++){
            ListNode* yet=lists[i];
            node=merge(node, yet);
        }
        return node;
    }
};
