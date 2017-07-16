/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL || l2 == NULL){
            return NULL;
        }
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        while(temp1 != NULL || temp2 != NULL){
            int v1 = temp1 == NULL ? 0 : temp1->val;
            int v2 = temp2 == NULL ? 0 : temp2->val;
            temp->val = v1 + v2 + carry;
            carry = temp->val / 10;
            temp->val = temp-> val % 10;
            if(temp1 != NULL){
                temp1 = temp1->next;
            }
            if(temp2 != NULL){
                temp2 = temp2->next;
            }
            ListNode* nextNode = new ListNode(0);
            temp->next = nextNode;
            temp = temp->next;
        }
        //处理进位
        temp->val = carry;
        //遍历去掉heading 0节点
        ListNode* lastNodeNotZero = head;
        ListNode* iNode = lastNodeNotZero->next;
        while(iNode != NULL){
            if(iNode->val != 0){
                lastNodeNotZero = iNode;
            }
            iNode = iNode->next;
        }
        lastNodeNotZero->next = NULL;
        return head;
    }
};
