/*
题目描述
输入一个链表，从尾到头打印链表每个节点的值。
*/

//算法：遍历链表将值push_back到vector中，用reserve方法

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> value;
        if(head != NULL) {
            value.push_back(head->val);
            while(head->next != NULL){
                value.push_back(head->next->val);
                head = head->next;
            }
        }
        reverse(value.begin(),value.end());
        return value;

    }
};
