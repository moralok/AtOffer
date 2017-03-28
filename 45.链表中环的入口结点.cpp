/*
题目描述
一个链表中包含环，请找出该链表的环的入口结点。
*/

//算法1:参考了别人的妙计，set真是好用呢，布吉岛是不是 !s.insert(p) 不能用呢 好像没有返回值
//算法2:两个指针先后紧接遍历，后一个拆开指向null，则最后到达的就是那个指针，但是链表被破坏了呢
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
		if(pHead==nullptr) return nullptr;
        set<ListNode*> s;
        ListNode *p;
        p=pHead;
        int size;
        while(p){
            size=s.size();
            s.insert(p);
            if(size==s.size())
                return p;
            p=p->next;
        }
        return nullptr;
    }
};
