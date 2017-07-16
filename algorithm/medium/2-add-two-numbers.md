## Add Two Numbers

###题目

https://leetcode.com/problems/add-two-numbers/#/description

题意是给出两个链表，链表表示一个数的倒叙排列，即链表的每个节点为一位数，7->0->8表示数字807，求这两个链表的和，用一个新的链表表示（同样为倒叙），要注意去掉头部多余的0。

### 解题思路 

可以理解为是高精度加法，但有点不同的是采用链表实现而不是数组实现。

通过创建一个新链表，遍历两个链表采用竖式加法即可。最后再遍历一遍新链表找出最后一个不为0的位置，把后面截断。

注意的一些细节：

1. 进位的处理，最后一位的进位。
2. 相加记得加上进位标记。
3. 考虑两个链表不同长度。
4. 考虑结果为0的情况。

示例代码

```
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
```

