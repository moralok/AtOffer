/*
题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

//算法1:就算再自己写一遍也很难写出这么棒的递归啊，怎么这么弱555
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
        if(pHead==nullptr) return nullptr;			//递归的出口
        if(pHead && pHead->next==nullptr) return pHead;
		ListNode *p1=pHead;
        if(pHead->val==pHead->next->val){			//开头相等不保留，两个指针还是有必要的
            p1=pHead->next->next;
            while(p1 && p1->val==pHead->val)
                p1=p1->next;
            return deleteDuplication(p1);
        }else{							//开头不等，须保留头结点
            p1=pHead->next;
            pHead->next=deleteDuplication(p1);
            return pHead;
        }
    }
};
//算法2:也很巧妙呢
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* first=new ListNode(-1); //创建一个新结点接在最前面简化第一个结点要去除的情况
        first->next=pHead;
        ListNode *p=pHead;		  //指针可在创建时赋值，作为前头兵
        ListNode *last=first;	          //作为跟踪连接的指针
        while(p && p->next){
            if(p->val==p->next->val){
                int val=p->val;
                while(p && p->val==val){
                    p=p->next;
                }
                last->next=p;
            }else{
                last=p;				//要连接新结点才用next
                p=p->next;
            }
        }
        return first->next;
    }
};


