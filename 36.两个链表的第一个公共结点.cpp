/*
题目描述
输入两个链表，找出它们的第一个公共结点。
*/

/*
算法
各自遍历
依次判断若不相同则->next 
若为空则跳到对方Head（抵消掉长度差值）
若有公共结点，长度相等一次可得，不等二次可得
无则返回nullptr
*/

/*
真的好巧妙啊 如果不认真看还以为作者忽略了什么情况
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *p1=pHead1;
        ListNode *p2=pHead2;
        while(p1!=p2){
            p1=p1==nullptr?pHead2:p1->next;
            p2=p2==nullptr?pHead1:p2->next;
        }
        return p1;
    }
};
