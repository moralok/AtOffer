/*
题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

//就算再自己写一遍也很难写出这么棒的递归啊，怎么这么弱555
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==nullptr) return nullptr;
        if(pHead && pHead->next==nullptr) return pHead;
		    ListNode *p1=pHead;
        if(pHead->val==pHead->next->val){
            p1=pHead->next->next;
            while(p1 && p1->val==pHead->val)
                p1=p1->next;
            return deleteDuplication(p1);
        }else{
            p1=pHead->next;
            pHead->next=deleteDuplication(p1);
            return pHead;
        }
    }
};

